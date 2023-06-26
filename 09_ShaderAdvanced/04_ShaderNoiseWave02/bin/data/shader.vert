#version 430

in vec4 position;
in vec4 color;
in vec3 normal;
uniform mat4 modelViewProjectionMatrix;

out Vertex {
 vec4 worldSpacePos;
 vec4 color;
 vec3 normal;
} oVert;

void main()
{
	gl_Position = modelViewProjectionMatrix * position;
	oVert.worldSpacePos = position;
	oVert.color = color;
	oVert.normal = normal;
}