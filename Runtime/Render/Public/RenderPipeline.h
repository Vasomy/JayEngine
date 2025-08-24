#pragma once
#ifndef RENDER_SCENE_H

#define RENDER_SCENE_H

#include"Numeric\JNumeric.h"

#include"ECS.h"

#include"Scene.h"
#include"RenderItem.h"

class FRenderPipeline
{
public:
	FRenderPipeline()
	{

	}

	// 准备渲染场景所需的内容，如管线，renderpass 着色器等等
	virtual void InitRenderState(int32 inD,int32 inH) = 0; 
	virtual void DrawCall() = 0;

	virtual void ProcessRenderData(const FScene& scene) = 0;

	int32 width, height;


	// an container storage RenderItem
		// if container is a dynamic array,
		// just use clear to reset array but not
		// reallocate or free array.
	TArray<FRenderItem> renderItems;
};


#endif // !RENDER_SCENE_H
