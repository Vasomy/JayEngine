#pragma once
#ifndef RHI_API

#if RUNTIME_EXPORT
#define RHI_API __declspec(dllexport)
#else
#define RHI_API __declspec(dllimport)
#endif // RUNTIME_EXPORT

#endif // !RHI_API

#include"Containers\Containers.h"
#include"RHIResource\RHIResource.h"
#include"FileSystem\FileSystem.h"
#ifndef RHI_DYNAMIC_H

#define RHI_DYNAMIC_H


// 
//
class RHI_API IRHIDynamic
{

public:
	// 在RenderSystem 初始化种，初始化rhi
public:

	virtual ~IRHIDynamic() {}

	virtual void Init() = 0;

	// call after RHI initialized called before render thread begin
	virtual void PostInit() = 0;

	// call before all RHI resource actually destroied (so all of RHI resource still available in Shutdown())
	virtual void Shutdown() = 0;

	virtual ERHIType GetRHIType() { return ERHIType::Undefined; }
	// return RHI primitive ptr
	virtual IRHIDynamic* GetNonValidationRHI() { return this; }

	// set current window handle
	// 如：是glfw则调用glfwMakeCurrentContext(GLFWWindow ptr)
	// win32 则是有关窗口的handle
	virtual void MakeCurrentWindowContext(FRHIWindowRef window) = 0;
	
	// 部分渲染API拥有自己的创建窗口的方式如（OPENGL）这时可以使用该函数快捷调用，若使用DX12则创建时使用win32的方式创建窗口
	virtual FRHIWindowRef CreateWindowByRHI(int32 width, int32 height, bool isFullScreen) = 0;

	virtual FRHIVertexArrayBufferRef CreateVertexBufferArray() = 0;
	virtual FRHIVertexArrayBufferRef CreateVertexBufferArray(
		const void* inVertexData,
		uint64 inVertexCount, uint64 inVertexElementSize,
		const void* indexData,
		uint64 inIndexCount, uint64 inIndexElementSize) = 0;

	virtual FRHIUniformbufferRef CreateUniformbuffer(uint64 size) = 0;
	virtual void UpdateUniformbuffer(FRHIUniformbuffer*target,const void* data, uint64 offset, uint64 size) = 0;

	virtual FRHIVertexShaderRef CreateVertexShader(TArray<char8>code) = 0;
	virtual FRHIPixelShaderRef CreatePixelShader(TArray<char8>code) = 0;

	virtual FRHITextureRef CreateTexture2D(FTextureDescription& desc,const void*data = nullptr) = 0;


	//
	virtual FRHIGraphicsPipelineStateRef CreateGraphicsPipelineState(FRHIGraphicsPipelineInitializer& initializer) = 0;
	virtual FRHIRenderpassRef CreateRenderpass(FRHIFramebufferInitializer&initializer) = 0;
	virtual FRHIFramebufferRef CreateFramebuffer(int32 width, int32 height, EFramebufferAttachmentFlags flags) = 0;
	virtual FRHIFramebufferRef CreateFramebuffer(FRHIFramebufferInitializer& initializer) = 0;



	virtual void ReadFramebufferPixels(FRHIFramebuffer*framebuffer,EFramebufferAttachmentFlagBits targetAttachment,int32 x, int32 y, int32 width,int32 height, EFormat frameFormat, void* outValue) = 0;

	// set global properties
	virtual void SetGraphicsPipelineState(FRHIGraphicsPipelineStateRef& graphicsPipelineState) = 0;
	virtual void BeginRenderpass(FRHIRenderpassRef& renderpass) = 0;
	virtual void EndRenderpass() = 0;
	// DC
	// something you need to do before render command called.
	// 1.bind graphics pipeline => set rasterization state, blend state.
	// 2.begin renderpass => major in set framebuffer state.
	// 3.draw call => draw call command, pass render data to render function.
	// 4.end renderpass => if not in opengl, transition the barrier of framebuffer's resource.
	// 5.handle something about swapchain => in opengl3 you need to do impl swapchain logic by you self
	//
	//virtual void RHIDrawIndexedIndirect(FRHIBuffer)
	virtual void RHIDrawIndexed(FRHIVertexArrayBuffer* VAO) = 0;
	virtual void RHIDrawIndexed(FRHIBuffer* vBuffer, FRHIBuffer* iBuffer) = 0;

	

private:

};


class RHI_API FRHIDynamicPSOFallback : public IRHIDynamic
{
public:
	virtual FRHIGraphicsPipelineStateRef CreateGraphicsPipelineState(FRHIGraphicsPipelineInitializer& initializer)override
	{
		FRHIGraphicsPipelineStateRef gpr;
		gpr.reset(new FRHIGraphicsPipelineState(initializer));
		
		return gpr;
	}
};
extern RHI_API TSmartPtr<IRHIDynamic> rhi;

inline static TSmartPtr<IRHIDynamic>& GetRHI()
{
	return rhi;
};

#endif // !RHI_DYNAMIC_H
