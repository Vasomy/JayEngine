#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texcoords;


layout(std140) uniform uColor
{
	vec4 color;
};

layout(std140) uniform uConstant
{
	mat4 view;
	mat4 proj;
	mat4 projView;// proj * view;
};

layout(std140) uniform uModel
{
	mat4 model;
};

out vec4 oColor;
out vec3 oNormal;

void main()
{
	oColor = color;

	gl_Position = projView*model*vec4(position,1.0f);
	//gl_Position = vec4(position.xy,0.0f,1.0f);

}