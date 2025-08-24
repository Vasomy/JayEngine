#pragma once
#ifndef RENDERDATACONTEXT_H
#define RENDERDATACONTEXT_H

#include"RenderData.h"
// flight render
// 如同交换链一般，渲染是准备两个帧缓冲，渲染到两个帧缓冲的渲染数据自然也不同，每次获取的是当前渲染数据
// 该渲染系统的flight num 为2
class FRenderSwapDataContext
{
public:
	FRenderSwapDataContext(){}
	FRenderSwapDataContext& operator=(const FRenderSwapDataContext& rhs)
	{
		projCamera = rhs.projCamera;
		constantBuffer = rhs.constantBuffer;
		objectColor = rhs.objectColor;
		objectModel = rhs.objectModel;
		return *this;
	}
	FRenderCamera* projCamera;

	FConstantBuffer constantBuffer;
	FColor objectColor;
	FMat4 objectModel;
private:
};
#endif // !RENDERDATACONTEXT_H