#pragma once

#include"RHIDynamic.h"
#include"Math\Math.h"
#include"MeshRenderComponent.h"
#include"CameraComponent.h"
class TRenderComponent
{
public:
	FVector3 position = FVector3(0.0f); 
	FVector4 color = FVector4(1.0f);
};


struct FTransform
{
	FVector3 position = FVector3(0.0f);
	FVector3 rotation = FVector3(0.0f);
	FVector3 scale = FVector3(1.0f);
	FVector4 color = FVector4(0.0f,0.0f,0.0f,1.0f);
};

//所有的Gameobject必须含有FTransformComponent

struct FTransformComponent
{
	FTransform transform;
	FMat4 Transform() const 
	{
		FMat4 rotation = glm::mat4(1.0f);
		rotation = glm::rotate(rotation, transform.rotation.x, { 1.0f,0.0f,0.0f });
		rotation = glm::rotate(rotation, transform.rotation.y, { 0.0f,1.0f,0.0f });
		rotation = glm::rotate(rotation, transform.rotation.z, { 0.0f,0.0f,1.0f });
		return 
			glm::translate(glm::mat4(1.0f), transform.position)
			* rotation
			* glm::scale(glm::mat4(1.0f), transform.scale)
			;
	}
};

struct FSpriteRenderer
{
	//FSprite sprite;

	FVector4 color;
};


