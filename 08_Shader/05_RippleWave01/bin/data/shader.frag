#version 430

uniform float u_time;
uniform vec2 u_resolution;
out vec4 fragColor;

void main(){
    // normalize gl_FragCoord.xy by u_resolution.xy
    vec2 vUV = gl_FragCoord.xy / u_resolution.xy;
    // calclate distance form center
    float len = length(vec2(0.5, 0.5) - vUV.xy);
    // draw ripple
    float br = sin(len * 120.0 - u_time * 40.0);
    fragColor = vec4(br, br, br, 1.0);
}