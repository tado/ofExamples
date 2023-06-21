#version 120

// receive float value from oF
uniform float u_time;

void main(){
    float r = abs(sin(u_time * 10.0));
    float g = abs(sin(u_time * 12.0));
    float b = abs(sin(u_time * 14.0));
    float a = 1.0;
    gl_FragColor = vec4(r, g, b, a);
}
