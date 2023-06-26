#version 150

in vec4 position;
in vec4 color;
in vec3 normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform float usingTexture;
uniform float usingColors;
uniform vec4 globalColor;
uniform sampler2D src_tex_unit0;

out Vertex {
 vec4 worldSpacePos;
 vec4 color;
 vec3 normal;
 vec2 texcoord;
} oVert;

void main()
{
	gl_Position = modelViewProjectionMatrix * position;
	oVert.worldSpacePos = position;
	oVert.color = color;
	oVert.normal = normal;
	oVert.texcoord = texcoord;
}