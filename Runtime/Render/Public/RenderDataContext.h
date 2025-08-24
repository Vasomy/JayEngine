#pragma once
#ifndef RENDERDATACONTEXT_H
#define RENDERDATACONTEXT_H

#include"RenderData.h"
// flight render
// ��ͬ������һ�㣬��Ⱦ��׼������֡���壬��Ⱦ������֡�������Ⱦ������ȻҲ��ͬ��ÿ�λ�ȡ���ǵ�ǰ��Ⱦ����
// ����Ⱦϵͳ��flight num Ϊ2
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