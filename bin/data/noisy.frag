#version 410
in float noiseAmt;
out vec4 outCol;

float bell(float _min,float _max,float value){
  float mid=(_min+_max)/2;
  return smoothstep(_min,mid,value)*smoothstep(_max,mid,value);
}

void main(){
  
  vec3 col=
  vec3(.3686,0.,0.)*smoothstep(.8,0,noiseAmt)+
  vec3(.1059,.0627,.7255)*bell(.4,.7,noiseAmt)+
  vec3(.0627,.7255,.4471)*bell(.5,.8,noiseAmt)+
  vec3(0.,1.,1.)*smoothstep(.5,1,noiseAmt);
  
  outCol=vec4(col,1);
}