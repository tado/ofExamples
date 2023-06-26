#version 150

uniform float u_time;

in Vertex {
    vec4 worldSpacePos;
    vec4 color;
    vec3 normal;
    vec2 texcoord;
} iVert;

out vec4 fragColor;

void main(){
    vec3 vUV = iVert.worldSpacePos.xyz;
    vec4 vColor = iVert.color;
    float r = sin(vUV.x * 0.2 + u_time * 10.0) + vColor.r;
    float g = sin(vUV.y * 0.2 + u_time * 10.0) + vColor.g;
    float b = sin(vUV.z * 0.2 + u_time * 10.0) + vColor.b;
    float a = 1.0;
    fragColor = vec4(r, g, b, a);
}
