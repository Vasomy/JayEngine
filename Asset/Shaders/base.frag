#version 330 core
in vec2 TexCoords;
out vec4 FragColor;
in vec4 oColor;



uniform sampler2D uTexture;



layout(std140) uniform uIsTex
{
	int isTex;
};

void main()
{
	FragColor = texture(uTexture,TexCoords)*oColor;
}