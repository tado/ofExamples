// by Danilo Guanabara
// http://www.pouet.net/prod.php?which=57245
// https://www.shadertoy.com/view/XsXXDn

#version 430
uniform float u_time;
uniform vec2 u_resolution;
out vec4 fragColor;

void main(){
    vec3 c;
	float l,z = u_time;
	for(int i = 0; i < 3; i++) {
		vec2 uv,p = gl_FragCoord.xy / u_resolution.xy;
		uv = p;
		p -= .5;
		p.x *= u_resolution.x / u_resolution.y;
		z += .07;
		l = length(p);
		uv += p / l * (sin(z) + 1.) * abs(sin(l * 9.-z-z));
		c[i] = .01 / length(mod(uv, 1.) - .5);
	}
	fragColor = vec4(c / l, u_time);
}