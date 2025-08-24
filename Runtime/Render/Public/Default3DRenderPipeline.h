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
	// ���������editor��ģʽ��������ui����������Ⱦ���
	// ���ΪgamemodeӦ������Ϸ��ʼ��ʱ����ȡ�����ڵ���camera
	FRenderCamera* camera = nullptr; 

	FConstantBuffer constantBuffer;

	
};

