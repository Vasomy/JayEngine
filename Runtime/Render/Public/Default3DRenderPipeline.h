#pragma once
#include"RenderPipeline.h"
#include"RenderCamera.h"
#include"RenderCommon.h"

#include"RenderItem.h"

#include"GameObject.h"
#include"RenderDataContext.h"

class FDefault3DRenderPipeline : public FRenderPipeline
{
	friend class FEditorMainCameraViewport;
public:
	~FDefault3DRenderPipeline();
	

	virtual void InitRenderState(int32 inW,int32 inH)override;
	virtual void DrawCall()override;
	virtual void ProcessRenderData(const FScene&scene)override;

	virtual void SetCamera(FRenderCamera*camera)
	{
		this->camera = camera;
	}

	void* GetFrameTexture() {
		return mainFrame->framebuffer->GetColorAttachmentTexture();
	}

	void UpdateCameraData(FRenderCamera* camera_);


private:

	// render 


	FRHIGraphicsPipelineStateRef colorPipeline;
	FRHIRenderpassRef			 mainFrame;
	
	//t
	FRHIVertexArrayBufferRef	tVAO;

	// uniformbuffer
	TSmartPtr<FRHIUniformbuffer> colorUBO;
	// constantbuffer 
	TSmartPtr<FRHIUniformbuffer> matrixUBO;
	// model matrix
	TSmartPtr<FRHIUniformbuffer> modelUBO;

	// render camera ptr
	// 如果引擎是editor的模式，则是由ui部分设置渲染相机
	// 如果为gamemode应该是游戏初始化时，获取场景内的主camera
	FRenderCamera* camera = nullptr; 

	FConstantBuffer constantBuffer;

	
};

