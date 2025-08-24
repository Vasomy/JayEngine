#version 330 core
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texcoords;
out vec2 TexCoords;

layout(std140) uniform uCameraInfo
{
	vec4 color;
};




out vec4 oColor;

void main()
{
	gl_Position = vec4(vertex.xy,0.0f,1.0f);
	TexCoords = texcoords;
	oColor = color;
}