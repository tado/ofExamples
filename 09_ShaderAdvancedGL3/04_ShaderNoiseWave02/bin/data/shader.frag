#version 150

uniform float u_time;

in Vertex {
    vec4 worldSpacePos;
    vec4 color;
    vec3 normal;
    vec2 texcoord;
} iVert;

out vec4 fragColor;

void main() {
    vec3 vUV = iVert.worldSpacePos.xyz;
    vec4 vColor = iVert.color;
    float r = cos(vUV.z / 80.0) * 0.5 + 1.0;
    float g = cos(vUV.z / 60.0) * 0.5 + 1.0;
    float b = cos(vUV.z / 40.0) * 0.5 + 1.0;
    float a = sin(vUV.y / 4.0 + u_time * 20.0) * 2.0;
    fragColor = vec4 (r, g, b, a);
}
