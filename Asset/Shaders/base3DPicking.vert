#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texcoords;

layout(std140) uniform u3DConstant
{
	mat4 projView;
};

layout(std140) uniform uModel
{
	mat4 model;
};

layout(std140) uniform uId
{
	int ettId;
};

flat out int oEttId;
void main()
{
	gl_Position = projView*model*vec4(position,1.0f);
	oEttId = ettId;
}