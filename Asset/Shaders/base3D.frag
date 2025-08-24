#version 330 core

in vec4 oColor;
in vec3 oNormal;
out vec4 color;

void main()
{
	color = vec4(oColor.xyz,1.0f);
}