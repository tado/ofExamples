#version 430

// receive float value from oF (elapsed time)
uniform float u_time;
// receive vec2 value from oF (resolution
uniform vec2 u_resolution;
// final color
out vec4 fragColor;

void main(){
    // normalize gl_FragCoord.xy by u_resolution.xy
    vec2 vUV = gl_FragCoord.xy / u_resolution.xy;
    float r = vUV.x;
    float g = vUV.y;
    float b = 0.0;
    float a = 1.0;
    fragColor = vec4(r, g, b, a);
}