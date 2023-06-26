#version 150

uniform float u_time;
uniform vec2 u_resolution;
out vec4 fragColor;

void main(){
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;
    float red = sin(uv.x * 20.0 + u_time * 10.0);
    float green = sin(uv.x * 22.0 + u_time * 10.0);
    float blue = sin(uv.x * 24.0 + u_time * 10.0);
    fragColor	= vec4(red,	green, blue, 1.0);
}
