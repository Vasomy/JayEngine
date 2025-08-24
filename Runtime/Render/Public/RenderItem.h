#pragma once
#ifndef RENDER_ITEM_H

#define RENDER_ITEM_H



#include"RHIDynamic.h"
#include"Math\Math.h"
// using VAO
#include"GameObject.h"

class FRenderItem
{
public:
	EntityID entityId;
	// 
	FMat4 model;
	FVector4f color = { 1,1,1,1 };


	FRHIVertexArrayBuffer* vertexArrayBuffer = nullptr;
};



#endif // !RENDER_ITEM_H
