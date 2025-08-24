#pragma once

#include"FOpenGL.h"
#include"RHIDynamic.h"
#include"RHIOpenGL3Resource\RHIOpenGL3Resource.h"
#include"RHIOpenGL3Resource\RHIOpenGL3TypeTraits.h"
#ifndef RHIOPENGLDYNAMIC_H
#define RHIOPENGLDYNAMIC_H

class RHI_API FRHIOpenGL3Dynamic : public FRHIDynamicPSOFallback
{
public:

	virtual ERHIType GetRHIType() { return ERHIType::OpenGL3; }

	virtual void Init()override;

	virtual void PostInit()override;

	virtual void Shutdown()override;

	virtual void MakeCurrentWindowContext(FRHIWindowRef window)override;
	virtual FRHIWindowRef CreateWindowByRHI(int32 width, int32 height, bool isFullScreen);

	virtual FRHIVertexArrayBufferRef CreateVertexBufferArray()override;
	virtual FRHIVertexArrayBufferRef CreateVertexBufferArray(
		const void* inVertexData,
		uint64 inVertexCount, uint64 inVertexElementSize,
		const void* indexData,
		uint64 inIndexCount, uint64 inIndexElementSize)override;
	virtual FRHIUniformbufferRef CreateUniformbuffer(uint64 size)override;
	virtual void UpdateUniformbuffer(FRHIUniformbuffer*target,const void* data, uint64 offset, uint64 size)override;


	virtual FRHIVertexShaderRef CreateVertexShader(TArray<char8>code)override;
	virtual FRHIPixelShaderRef CreatePixelShader(TArray<char8>code)override;

	virtual FRHITextureRef CreateTexture2D(FTextureDescription& desc,const void*data = nullptr)override;
	
	// 因为OpenGL具有状态机的特征
	// 因此在RHI创建完GraphicsPipeline或者Renderpass后，会立即记录该状态
	// 以便后续部分资源的创建，如VAO会查找当前绑定的渲染管线的属性，着色器输入布局（着色器装配阶段）
	virtual FRHIGraphicsPipelineStateRef CreateGraphicsPipelineState(FRHIGraphicsPipelineInitializer& initializer)override;
	virtual FRHIRenderpassRef CreateRenderpass(FRHIFramebufferInitializer& framebuffer) override;
	virtual FRHIFramebufferRef CreateFramebuffer(int32 width,int32 height,EFramebufferAttachmentFlags flags)override;
	virtual FRHIFramebufferRef CreateFramebuffer(FRHIFramebufferInitializer& initializer)override;

	virtual void ReadFramebufferPixels(FRHIFramebuffer* framebuffer, EFramebufferAttachmentFlagBits targetAttachment, int32 x, int32 y, int32 width, int32 height, EFormat frameFormat, void* outValue)override;


	virtual void SetGraphicsPipelineState(FRHIGraphicsPipelineStateRef& graphicsPipelineState)override;
	//virtual void SetRasterizerState();
	virtual void BeginRenderpass(FRHIRenderpassRef& renderpass)override;
	virtual void EndRenderpass()override;


	// DC
	virtual void RHIDrawIndexed(FRHIVertexArrayBuffer* vao)override;
	virtual void RHIDrawIndexed(FRHIBuffer* vBuffer, FRHIBuffer* iBuffer)override;

private:
	// 比较重要的函数，可能会多次扩充
	void SetUpRenderState();
	void EndUpRenderState();
public:
	template<typename RHIR_T>// RHIR_T 为要转换的 RHIResource类型
	typename RHIOpenGL3TypeTraits<RHIR_T>::type* ResourceCast(RHIR_T* ptr)
	{
		return static_cast<RHIOpenGL3TypeTraits<RHIR_T>::type*>(ptr);
	}
	// 指针转换
	template<typename target_RHI_T,typename RHIR_T>
	typename std::remove_pointer<target_RHI_T>::type * ResourceCast(RHIR_T*ptr)
	{
		return static_cast<typename std::remove_pointer<target_RHI_T>::type *>(ptr);
	}
};


#endif // !RHIOPENGLDYNAMIC_H