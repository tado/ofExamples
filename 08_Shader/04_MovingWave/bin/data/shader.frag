#version 430

uniform float u_time;
uniform vec2 u_resolution;
out vec4 fragColor;

void main(){
    // normalize gl_FragCoord.xy by u_resolution.xy
    vec2 vUV = gl_FragCoord.xy / u_resolution.xy;
    // draw a moving waves
    float r = sin(u_time * 10.0 + vUV.x * 12.0);
    float g = sin(u_time * -10.0 + vUV.x * 12.0);
    float b = sin(u_time * 10.0 + vUV.y * 8.0);
    float a = 1.0;
    fragColor = vec4(r, g, b, a);
}