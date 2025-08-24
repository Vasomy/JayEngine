#pragma once
#include"Containers\Containers.h"
#include"RHIDefinition.h"
#include"Numeric\JNumeric.h"
#include"Math\Math.h"

#define RHI_FORWARD_DECLARE(clazz) class clazz; using clazz##Ref = SmartPtr<clazz>;





struct FShaderInputLayoutPart
{
	FString paramterName;
	uint32 paramterCount;// 有几个元素 
	uint32 elementSize;// 每个元素大小
	uint32 semanticIndex;
	EFormat format;
	uint32 inputSlot;
	uint32 offset;
	
	auto& SetParamterName(FString& name)
	{
		paramterName = name;
		return*this;
	}
	auto& SetParamterName(const char* name)
	{
		paramterName = name;
		return*this;
	}
	auto& SetParamterCount(uint32 count)
	{
		paramterCount = count;
		return*this;
	}
	auto& SetElementSize(uint32 size)
	{
		elementSize = size;
		return*this;
	}
	auto& SetSemanticIndex(uint32 index)
	{
		semanticIndex = index;
		return*this;
	}
	auto& SetFormat(EFormat iFormat)
	{
		format = iFormat;
		return*this;
	}
	auto& SetInputSlot(uint32 index)
	{
		inputSlot = index;
		return*this;
	}
	auto& SetOffset(uint32 offset)
	{
		this->offset = offset;
		return*this;
	}
};

struct FShaderInputLayout
{
	TArray<FShaderInputLayoutPart>shaderInputs;
	auto& SetShaderInputs(const TArrayProxy<FShaderInputLayoutPart>parts) { shaderInputs = parts.AsArray(); return*THIS; }
};


struct FDepthStencilValue
{
	float32 depth = 1.0f;
	uint32  stencil = 0;
};

struct FClearColorValue
{
	FClearColorValue()
	{
		value.color = { 1.0f,1.0f,1.0f,1.0f };
		binding = CVB_Color;
	}
	FClearColorValue(FVector4f inColor)
	{
		value.color = inColor;
		binding = CVB_Color;
	}
	FClearColorValue(float32 r, float32 g, float32 b, float32 a = 1.0f)
	{
		value.color = { r,g,b,a };
		binding = CVB_Color;
	}
	FClearColorValue(FDepthStencilValue inDsv, EClearValueBinding inBinding = CVB_DepthStencil)
	{
		value.dsv = inDsv;
		binding = CVB_DepthStencil;
	}
	FClearColorValue(float32 depth, uint32 stencil)
	{
		value.dsv = { depth,stencil };
		binding = CVB_DepthStencil;
	}

	union ClearValue
	{
		FVector4f color{};
		FDepthStencilValue dsv;

	}value;
	EClearValueBinding binding = CVB_Color;
	 
	float* GetPClearColor() const
	{
		AssertIfCheckResult( binding != CVB_Color ,"User want to get the 'clear color',but binding is 'depth stencil'!")
		return (float*)&value.color;
	}
	FVector4f GetClearColor() const
	{
		AssertIfCheckResult(binding != CVB_Color, "User want to get the 'clear color',but binding is 'depth stencil'!")
		return value.color;
	}
	float32 GetClearDepth() const
	{
		AssertIfCheckResult(binding != CVB_DepthStencil, "User want to get the 'depth', but binding is 'clear color'!")
		return value.dsv.depth;
	}
	uint32 GetClearStencil() const
	{
		AssertIfCheckResult(binding != CVB_DepthStencil, "User want to get the 'stencil', but binding is 'clear color'!")
		return value.dsv.stencil;
	}
	FDepthStencilValue GetClearDepthStencil()const
	{
		AssertIfCheckResult(binding != CVB_DepthStencil, "User want to get the 'depth & stencil', but binding is 'clear color'!")
		return value.dsv;
	}
};

// 实为 2D纹理描述符
struct FTextureDescription
{
	
	uint32 width;
	auto& SetWidth(uint32 inW) { width = inW; return *this; }
	uint32 height;
	auto& SetHeight(uint32 inH) { height = inH; return*this; }
	EFormat format;
	auto& SetFormat(EFormat inF) { format = inF; return*this; }
	//size of elements in texture
	uint32 arraySize = 1;
	auto& SetArraySize(uint32 inAS) { arraySize = inAS; return*this; }
	// depth if texture is Texture2D
	uint32 depth = 1;
	auto& SetDepth(uint32 inD) { depth = inD; return *this; }
	uint8 numMips = 1;
	auto& SetNumMips(uint8 inNM) { numMips = inNM; return*THIS; }
	uint8 numSamplers = 5;
	auto& SetNumSamplers(uint8 inNS) { numSamplers = inNS; return*THIS; }

	// 2D纹理坐标两种表示 (u,v) (s,t) 
	ESamplerAddress uAddressMode = ESamplerAddress::SA_NONE;
	auto& SetUAddressMode(ESamplerAddress inA) { uAddressMode = inA; return*THIS; }
	ESamplerAddress vAddressMode = ESamplerAddress::SA_NONE;
	auto& SetVAddressMode(ESamplerAddress inV) { vAddressMode = inV; return*THIS; }

	ESamplerFilter minFilter = ESamplerFilter::SF_NONE;
	auto& SetMinFilter(ESamplerFilter inM) { minFilter = inM; return*THIS; }
	ESamplerFilter maxFilter = ESamplerFilter::SF_NONE;
	auto& SetMaxFilter(ESamplerFilter inM) { maxFilter = inM; return*THIS; }

	FClearColorValue clearColorValue;
	auto& SetClearValueBinding(EClearValueBinding binding) { clearColorValue.binding = binding; return*THIS; }
	auto& SetClearValue(const FClearColorValue& inCCV) { clearColorValue = inCCV; return*THIS; }
	auto& SetColorClearValue(FVector4f inC) { clearColorValue.binding = CVB_Color; clearColorValue.value.color = inC; return*THIS; }
	auto& SetDepthClearValue(float32 inD) { clearColorValue.binding = CVB_DepthStencil; clearColorValue.value.dsv.depth = inD; return*THIS; }
	auto& SetStencilClearValue(uint32 inS) { clearColorValue.binding = CVB_DepthStencil; clearColorValue.value.dsv.stencil = inS; return*THIS; }

	glm::vec4 GetClearColor() const
	{
		return clearColorValue.GetClearColor();
	}
	float32* GetPClearColor() const
	{
		return clearColorValue.GetPClearColor();
	}
	float32 GetClearDepth()const
	{
		return clearColorValue.GetClearDepth();
	}
	uint32 GetClearStencil()const
	{
		return clearColorValue.GetClearStencil();
	}
	FDepthStencilValue GetClearDepthStencil()const
	{
		return clearColorValue.GetClearDepthStencil();
	}
};

struct FAttachmentReference
{
	
	uint32 index; 
	auto& SetEAttachmentIndex(uint32 in_index)
	{
		index = in_index; 
		return *this;
	}
	
	uint32& GetEAttachmentIndex() 
	{
		return index;
	}
	EFramebufferAttachmentFlags attachment;
	auto& SetEFramebufferAttachment(EFramebufferAttachmentFlagBits bits)
	{
		attachment = bits;
		return *this;
	}
};

struct FRasterizationState
{
	bool discardEnable = false;
	auto& SetDiscardEnable(bool DE) { discardEnable = DE; return*THIS; }
	ECullMode cullMode = ECullMode::CM_None;
	auto& SetECullMode(ECullMode eCullMode) { cullMode = eCullMode; return*THIS; }
	EFrontFace frontFace = EFrontFace::FF_CounterClockwise;
	auto& SetEFrontFace(EFrontFace eFrontFace) { frontFace = eFrontFace; return*THIS; }
	EPolygonMode polygonMode = EPolygonMode::PM_Fill;
	auto& SetEPolygonMode(EPolygonMode ePolygonMode) { polygonMode = ePolygonMode; return*THIS; }
	float32 lineWidth = 1.0f; // 只有在 polygonMode 为 PM_Line 时才会被用到
	auto& SetLineWidth(float LW) { lineWidth = LW; return*THIS; }
	bool enableDetphTest = false;
	auto& SetDepthTest(bool InDT) { enableDetphTest = InDT; return*THIS; }
	// 深度测试和模板测试在beginrenderpass时启用
	/*bool depthTestEnable = false;
	auto& SetDepthTestEnable(bool inD) { depthTestEnable = inD; return*THIS; }
	bool stencilTestEnable = false;
	auto& SetStencilTestEnable(bool inS) { stencilTestEnable = inS; return*THIS; }*/
};
