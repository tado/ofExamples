#version 430

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
    float red = sin(vUV.x * 0.2 + u_time * 10.0) + vColor.r;
    float green = sin(vUV.y * 0.2 + u_time * 10.0) + vColor.g;
    float blue = sin(vUV.z * 0.2 + u_time * 10.0) + vColor.b;
    float alpha = 1.0;
    fragColor = vec4(red, green, blue, alpha);
}
