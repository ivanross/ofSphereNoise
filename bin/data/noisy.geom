#version 410
layout(triangles)in;
layout(triangle_strip,max_vertices=3)out;

in VertOut{
  float noise;
  vec4 pos;
  vec3 worldPos;
}vert[];

out float noiseAmt;
out vec3 fragNrm;
out vec3 fragWorldPos;

void main(){
  vec3 a=(vert[0].pos-vert[1].pos).xyz;
  vec3 b=(vert[2].pos-vert[1].pos).xyz;
  vec3 N=normalize(cross(a,b));
  
  for(int i=0;i<vert.length();++i){
    
    gl_Position=vert[i].pos;
    fragWorldPos=vert[i].worldPos;
    noiseAmt=vert[i].noise;
    fragNrm=N;
    EmitVertex();
  }
  
  EndPrimitive();
}