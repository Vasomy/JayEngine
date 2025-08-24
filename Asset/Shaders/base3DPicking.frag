#version 330 core

out vec4 color;
flat in int oEttId;

void main()
{
	color = vec4(0,oEttId,0,1);
}