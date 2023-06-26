#version 430

uniform float u_time;
uniform vec2 u_resolution;

in Vertex {
    vec4 worldSpacePos;
    vec4 color;
    vec3 normal;
} iVert;

out vec4 fragColor;

void main() {
    vec3 vUV = iVert.worldSpacePos.xyz;
    vec4 vColor = iVert.color;
    float r = abs(sin(vUV.z * 0.16 + u_time * 12.0)) * 1.5;
    float g = abs(sin(vUV.z * 0.14 + u_time * 14.0)) * 1.5;
    float b = abs(sin(vUV.z * 0.12 + u_time * 16.0)) * 1.5;
    float a = abs(sin(vUV.z * 0.08 + u_time * 10.0));
    fragColor = vec4(r, g, b, a);
}
