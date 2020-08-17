#version 410

uniform samplerCube envMap;
uniform vec3 ambientCol;
in vec3 fromCam;
out vec4 outCol;

void main(){
  vec3 envCol=texture(envMap,fromCam).xyz;
  vec3 ambient=envCol*ambientCol;
  outCol=vec4(ambient,1);
}
