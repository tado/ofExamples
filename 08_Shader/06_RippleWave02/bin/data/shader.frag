#version 430

uniform float u_time;
uniform vec2 u_resolution;
out vec4 fragColor;

void main(){
    // normalize pixel coordinate to 0.0 - 1.0
    vec2 uv = (gl_FragCoord.xy * 2.0 - u_resolution) / vec2(u_resolution.x, u_resolution.x);
    // calclate distance form center
    float len = length(uv);
    // draw ripple
    float r = sin(len * 120 - u_time * 40.0);
    float g = sin(len * 120 - u_time * 40.0 - 1.0);
    float b = sin(len * 120 - u_time * 40.0 - 2.0);
    fragColor = vec4(r, g, b, 1.0);
}