#pragma once
#include"Numeric\JNumeric.h"
#include"SmartPtr\SmartPtr.h"
#include"RHIDefinition.h"
#include"RHICommon.h"
#include<functional>

#ifndef RHI_RESOURCE_REF_DEFINE
#define RHI_RESOURCE_REF_DEFINE

RHI_FORWARD_DECLARE(FRHIVertexShader)
RHI_FORWARD_DECLARE(FRHIPixelShader)
RHI_FORWARD_DECLARE(FRHIWindow)
RHI_FORWARD_DECLARE(FRHIGraphicsPipelineState)
RHI_FORWARD_DECLARE(FRHIFramebuffer)
RHI_FORWARD_DECLARE(FRHIRenderpass)
RHI_FORWARD_DECLARE(FRHIVertexArrayBuffer)
RHI_FORWARD_DECLARE(FRHITexture)
RHI_FORWARD_DECLARE(FRHIUniformbuffer)


#endif // !RHI_RESOURCE_REF_DEFINE


struct FShaderState
{

	// shaderType ˵�� һ����������ɫ��������ʲô��ɫ�������㣬Ƭ�Σ����Σ����㣩
	EShaderTypeFlag shaderTypeFlags;
	auto& SetEShaderTypeFlag(EShaderTypeFlag& in_shaderTypeFlags) {
		shaderTypeFlags = in_shaderTypeFlags; return *this;
	}
	auto& SetEShaderTypeFlag(EShaderTypeFlag&& in_shaderTypeFlags) {
		shaderTypeFlags = in_shaderTypeFlags; return *this;
	}
	GEN_CLASS_SET_INFO(FRHIVertexShaderRef, vertexShader)
	GEN_CLASS_SET_INFO(FRHIPixelShaderRef, pixelShader)
};

RHI_FORWARD_DECLARE(FShaderStateCache)
struct FShaderStateCache
{
	bool isCached = false;
};

// ������ɫ����uniform����������
// Ŀǰֻ��֧��һ��uniformbuffer��Ӧһ��binding
struct FRHIUniformAttribution final
{
	EUniformUsage usage;
	auto& SetUniformType(EUniformUsage inT) { usage = inT; return*THIS; }
	FString name;
	auto& SetName(FString& inN) { name = inN; return*THIS; }
	auto& SetName(const char* inN) { name = inN; return*THIS; }
	uint64 size;
	auto& SetSize(uint64 inS) { size = inS; return*THIS; }
	uint32 binding;// ����texture uniform�У�binding��Ӧtexture����ţ��� GL_TEXTURE_0...123��
	// ��OpenGL�£�ֻ�е�usage Ϊ constantbufferʱ�����ֶ�ָ�������������api���л�ȡ
	auto& SetBinding(uint32 inB) { binding = inB; return*THIS; }
	FRHIUniformbuffer* uniformbuffer = nullptr;// ��texture��ѡһ
	auto& SetPUniformbuffer(FRHIUniformbuffer* inU) { uniformbuffer = inU; return*THIS; }
	FRHITexture* texture = nullptr;
	uint32 textureBinding; // ��uniform Ϊsampled �ñ�����Ӧ����ɫ���У��󶨵�uniform����
	auto& SetPTexture(FRHITexture* inT) { texture = inT; return*THIS; }

	using BindFunction = std::function<void()>;
	using UnBindingFunction = std::function<void()>;

	BindFunction bindFunc;
	UnBindingFunction unbindFunc;
	auto& SetBindingFunction(const BindFunction& inF) { bindFunc = inF; return*THIS; }
	auto& SetUnBindingFunction(const UnBindingFunction& inF) { unbindFunc = inF; return *THIS; }



};
struct FRHIUniformState final
{
	TArray<FRHIUniformAttribution> attributions;
	auto& SetPAttributions(const TArrayProxy<FRHIUniformAttribution>&inAttributions)
	{
		attributions = inAttributions.AsArray();
		return*THIS;
	}
};
// ������Ⱦ���ߵĳ�ʼ����Ϣ�Ͳ�������
// ������Set��������Ҫ�����ֲ����룩�û����ã�
// û��Set�����ı���Ϊ����Ĺ���״̬����Ӧ�ñ��û��޸ģ������Ա��û�����
struct FRHIGraphicsPipelineInitializer
{
	
	GEN_CLASS_SET_INFO(FShaderInputLayout, shaderInput)
	GEN_CLASS_SET_INFO(FShaderState, shaderState)
	FShaderStateCacheRef		shaderStateCache;
	FRasterizationState			rasterizationSate;
	FRHIUniformState			uniformState;
	auto& SetUniformState(FRHIUniformState& inUS) { uniformState = inUS; return*THIS; }
	EPrimitiveTopologyType		primitiveTopology = PPT_Triangle;
	/*ShaderInputLayout ShaderLayout;
	RasterizerState RasterizerState;
	BlendState BlendStateDesc;
	uint32 Samplemask = UINT_MAX;
	EPrimitiveTopologyType TopologyType = PTT_Triangle;
	uint32 NumRenderTargets;
	Format RtvFormat;
	SampleDesc Sampledesc;
	Format DsvFormat;
	DepthStencilDesc DSDesc;*/
};



class FRHIResource
{
public:
	FRHIResource(ERHIResourceType type)
		:type(type)
	{

	}
	virtual ~FRHIResource() {}
	void Destroy(){
	
	}
	void Reset() {

	}
	ERHIResourceType GetType() { return type; }
private:
	ERHIResourceType type;
};

class FRHIWindow : public FRHIResource
{
public:
	using MouseCallBackFunc = std::function<void(float64 xPos,float64 yPos)>;
	// ����ͨ�����ַ�ʽ����
	// win32 ��� 
	// glfw �������ô���
	enum EWindowType
	{
		undefined,// ��δ������
		win32,
		glfw
	};

	FRHIWindow(EWindowType windowType,int32 width,int32 height,bool isFullScreen)
		:FRHIResource(RRT_Window),width(width),height(height),isFullScreen(isFullScreen)
	{
		activedWindow = this;
	}
	virtual ~FRHIWindow() {}
	
	
	virtual bool ShouldClose() = 0;
	virtual void PollEvents() = 0;
	virtual void SwapBuffers() = 0;

	virtual float32 GetRunningTime() = 0;

public:
	int32 width;
	int32 height;
	bool isFullScreen;

public:
	inline static EWindowType windowType = undefined;
	inline static FRHIWindow* activedWindow = nullptr;
};

class FRHIVertexShader : public FRHIResource
{
public:
	FRHIVertexShader()
		:FRHIResource(RRT_VertexShader)
	{

	}
protected:
	char8* byteCode = nullptr;
};

class FRHIPixelShader : public FRHIResource
{
public:
	FRHIPixelShader()
		:FRHIResource(RRT_PixelShader)
	{

	}
protected:
	char8* byteCode = nullptr;
};



class FRHIGraphicsPipelineState : public FRHIResource
{
public:
	FRHIGraphicsPipelineState(FRHIGraphicsPipelineInitializer& initializer_)
		:FRHIResource(RRT_PixelShader),initializer(initializer_)
	{

	}

	FRHIGraphicsPipelineInitializer initializer;
};

class FRHIBuffer : public FRHIResource
{
public:
	FRHIBuffer(uint64 inSize,uint32 inStride,uint64 inCount,const void*inData = nullptr)
		:FRHIResource(RRT_Buffer),size(inSize),stride(inStride),count(inCount)
	{
		if (inData)
			BufferData(inData);
	}
	virtual ~FRHIBuffer()
	{

	}

	void ResetBuffer(uint64 inSize, uint32 inStride, uint64 inCount, const void* inData = nullptr)
	{
		ReleaseBuffer();
		size = inSize;
		stride = inStride;
		count = inCount;
		BufferData(inData);
	}
	virtual void BufferData(const void* data) = 0;
	virtual void CopyBuffer(const FRHIBuffer* buffer) = 0;
	virtual void ReleaseBuffer() = 0;
	virtual void Bind() = 0;

private:
	uint64 size;
	uint32 stride; // sizeof T
	uint64 count;
};
// 
class FRHIUniformbuffer :public FRHIResource
{
public:
	FRHIUniformbuffer()
		:FRHIResource(RRT_Uniformbuffer)
	{

	}


	virtual void BufferData(const void* data, uint64 size) = 0;
	virtual void BufferSubData(const void* data, uint64 offset, uint64 size) = 0;

	void* data;
	uint64 size;
};

// ���� vertex buffer �� index buffer �� ��Ҫ���������ƵĶ����mesh�����ݴ��浽VertexArrayBuffer
class FRHIVertexArrayBuffer : public FRHIResource
{
public:
	FRHIVertexArrayBuffer()
		:FRHIResource(RRT_VertexArrayBuffer)
	{

	}

	explicit FRHIVertexArrayBuffer(
		void* inVD,uint64 inVC,uint64 inVS,
		void* inID,uint64 inIC,uint64 inIS)
		:vertexData(inVD),vertexCount(inVC),vertexElementSize(inVS),
		indexData(inID),indexCount(inIC),indexElementSize(inIS),
		FRHIResource(RRT_VertexArrayBuffer)
	{

	}

	virtual ~FRHIVertexArrayBuffer()
	{

	}
	uint64 indexCount;
	uint64 indexElementSize;
	// ����ṹ��������������������ռ��СΪ vertexCount * vertexElementSize
	uint64 vertexCount;
	uint64 vertexElementSize;
	void* indexData;
	void* vertexData;

	virtual void BufferVertexData(void* inData, uint64 inVertexCount, uint64 inVertexElementSize) = 0;
	virtual void BufferIndexData(void* inData, uint64 inIndexCount, uint64 inIndexElementSize) = 0;
};

// framebuffer ���� depthStenclState

struct FRHIFramebufferInitializer
{
	int32 width;
	auto& SetWidth(int32 inW) { width = inW; return*THIS; }
	int32 height;
	auto& SetHeight(int32 inH) { height = inH; return*THIS; }
	EFramebufferAttachmentFlags attachmentFlags;
	auto& SetAttachmentFlags(EFramebufferAttachmentFlags bits) { attachmentFlags = bits; return*THIS; }
	FVector4f clearColor;
	float32 clearDepth;
	uint32 clearStencil;
	auto& SetClearColor(FVector4f& inC) { clearColor = inC; return *THIS; }
	auto& SetClearColor(FVector4f&& inC) { clearColor = inC; return *THIS; }
	auto& SetClearDepth(float32 inD) { clearDepth = clearDepth; return*THIS; }
	auto& SetClearStencil(uint32 inS) { clearStencil = inS; return*THIS; }
};

class FRHITexture : public FRHIResource
{
public:
	FRHITexture(FTextureDescription& desc, ETextureType inTextureType)
		:FRHIResource(RRT_Texture), textureType(inTextureType)
	{
		SetTextureDescription(desc);
	}

	ETextureType textureType = TT_Undefined;
	FTextureDescription	 textureDesc;
	void SetTextureDescription(FTextureDescription& inTexDesc)
	{
		textureDesc = inTexDesc;
	}
	const FTextureDescription& GetTextureDescription()const
	{
		return textureDesc;
	}


};

class FRHIFramebuffer : public FRHIResource
{
public:
	FRHIFramebuffer(int32 inWidth,int32 inHeight, EFramebufferAttachmentFlags eframebufferattachment)
		:FRHIResource(RRT_Framebuffer), framebufferAttachments(eframebufferattachment),width(inWidth),height(inHeight)
	{

	}
	FRHIFramebuffer(FRHIFramebufferInitializer& initializer)
		:width(initializer.width)
		,height(initializer.height)
		,framebufferAttachments(initializer.attachmentFlags)
		,initializer(initializer)
		,FRHIResource(RRT_Framebuffer)
	{

	}
	virtual ~FRHIFramebuffer()
	{

	}

	virtual void* GetColorAttachmentTexture()const // ��ȡ֡�������ɫ�����Ĳ���
	{
		return nullptr;
	}

	EFormat GetColorFormat() const
	{
		for (auto& attachmentRef : attachmentsReference)
		{
			if (attachmentRef.attachment == EFramebufferAttachmentFlagBits::FA_Color)
			{
				auto& attachment = attachments[attachmentRef.index];
				return attachment->GetTextureDescription().format;
			}
		}
		assert(("Framebuffer Cant find color attachment!", 0));
	}
	
	bool HaveColorAttachment()
	{
		return static_cast<bool>(framebufferAttachments & EFramebufferAttachmentFlagBits::FA_Color);
	}

	bool HaveDepthAttachment()
	{
		return
			static_cast<bool>(framebufferAttachments & EFramebufferAttachmentFlagBits::FA_Depth)
			||
			static_cast<bool>(framebufferAttachments & EFramebufferAttachmentFlagBits::FA_DepthStencil);
	}

	bool HaveStencilAttachment()
	{
		return
			static_cast<bool>(framebufferAttachments & EFramebufferAttachmentFlagBits::FA_Stencil)
			||
			static_cast<bool>(framebufferAttachments & EFramebufferAttachmentFlagBits::FA_DepthStencil)
			;
	}


	FRHIFramebufferInitializer initializer;

	int32 width, height; // color attachment
	EFramebufferAttachmentFlags framebufferAttachments; // ��״̬ö��˵����framebuffer ��ʲô����

	TArray<FRHITextureRef> attachments;
	TArray<FAttachmentReference> attachmentsReference;
};





class FRHIRenderpass : public FRHIResource
{
public:
	FRHIRenderpass()
		:FRHIResource(RRT_Renderpass)
	{

	}
	
	int32 GetFrameWidth()
	{
		return framebuffer->width;
	}
	int32 GetFrameHeight()
	{
		return framebuffer->height;
	}

	FVector4f GetClearColor()
	{
		auto* ptr = framebuffer.get();
		for (auto p : ptr->attachmentsReference)
		{
			if (p.attachment & EFramebufferAttachmentFlagBits::FA_Color)
			{
				return ptr->attachments[p.index]->GetTextureDescription().GetClearColor();
			}
		}
		return { 1,0,0,1 };
	}

	FDepthStencilValue GetClearDepthStencil()
	{
		auto* ptr = framebuffer.get();
		for (auto p : ptr->attachmentsReference)
		{
			if (p.attachment & EFramebufferAttachmentFlagBits::FA_DepthStencil)
			{
				return ptr->attachments[p.index]->GetTextureDescription().GetClearDepthStencil();
			}
		}
		return { 0.0f,0 };
	}

	virtual ~FRHIRenderpass()
	{

	}
	FRHIFramebufferRef framebuffer;
};






