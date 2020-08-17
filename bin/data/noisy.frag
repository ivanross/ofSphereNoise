#version 410

in float noiseAmt;
in float noiseAmt2;
in vec3 fragNrm;
in vec3 fragWorldPos;

uniform samplerCube envMap;
uniform vec3 lightDir;
uniform vec3 lightCol;
uniform vec3 ambientCol;
uniform vec3 cameraPos;

out vec4 outCol;

float bell(float _min,float _max,float value){
  float mid=(_min+_max)/2;
  return smoothstep(_min,mid,value)*smoothstep(_max,mid,value);
}

vec3 noiseColor(float n){
  vec3 col=
  vec3(.3686,0.,0.)*smoothstep(.8,0,n)+
  vec3(.1059,.0627,.7255)*bell(.4,.7,n)+
  vec3(.0627,.7255,.4471)*bell(.5,.8,n)+
  vec3(0.,1.,1.)*smoothstep(.5,1,n);
  return col;
}

void main(){
  
  vec3 nrm=normalize(fragNrm);
  vec3 viewDir=normalize(cameraPos-fragWorldPos);
  
  vec3 col=noiseColor(noiseAmt);
  vec3 envSample=texture(envMap,reflect(-viewDir,nrm)).xyz;
  
  float mixCoeff=smoothstep(-.5,.5,noiseAmt2*2-1)+.5;
  col=mix(envSample,col,mixCoeff);
  
  float diffuseAmt=max(0,dot(nrm,lightDir));
  vec3 diffuseCol=lightCol*col*diffuseAmt;
  
  vec3 halfVec=normalize(viewDir+lightDir);
  float specularAmt=max(0,dot(halfVec,nrm));
  specularAmt=pow(specularAmt,128.);
  vec3 specularCol=specularAmt*lightCol;
  
  vec3 ambient=ambientCol*col;
  
  outCol=vec4(specularCol+diffuseCol+ambient,1);
}