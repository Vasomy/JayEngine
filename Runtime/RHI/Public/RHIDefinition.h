#pragma once
#ifndef RHI_DEFINITIONS_H
#define RHI_DEFINITIONS_H

#include"Flags.h"
#include"Numeric\JNumeric.h"

enum ERHIType
{
	Undefined,
	D3D12,
	OpenGL3
};

enum EClearValueBinding
{
	CVB_Color,
	CVB_DepthStencil
};

enum ERHIResourceType
{
	RRT_Resource,
	RRT_Window,
	RRT_VertexShader,
	RRT_PixelShader,
	RRT_GraphicsPipeline,
	RRT_Buffer,
	RRT_VertexArrayBuffer,
	RRT_Framebuffer, 
	RRT_Renderpass,
	RRT_Texture,
	RRT_Uniformbuffer,
	RRT_UniformbufferBindingState,
	
};

enum ERHIDepthStencilState
{
	None, // no Depth and Stencil
	DSS_Depth32,
	DSS_Depth24Stencil8,
};

enum class EFramebufferAttachmentFlagBits : int32
{
	FA_Color = 1,
	FA_Depth = 1<<1,
	FA_Stencil = 1<<2,
	FA_DepthStencil = 1<<3,
};
using EFramebufferAttachmentFlags = Flags<EFramebufferAttachmentFlagBits>;
template<>
struct FlagTraits<EFramebufferAttachmentFlagBits>
{
	constexpr static bool isBitMask = true;
};

enum EPrimitiveTopologyType
{
	PPT_Unknow,
	PPT_Triangle,
	PPT_TriangleStrip,
	PPT_TriangleFan,
	PPT_Point,
	PPT_Line,
	PPT_LineStrip,
	PPT_LineLoop,

};
enum EFormat
{
	F_Unknow,
	F_R32G32B32A32_Typeless,
	F_R32G32B32A32_Float,
	F_R32G32B32A32_Sint,
	F_R32G32B32A32_Uint,
	F_R32G32B32A32_SNorm,
	F_R32G32B32A32_UNorm,
	F_R32G32B32_Typeless,
	F_R32G32B32_Float,
	F_R32G32B32_Sint,
	F_R32G32B32_Uint,
	F_R32G32B32_SNorm,
	F_R32G32B32_UNorm,
	F_R16G16B16A16_Typeless,
	F_R16G16B16A16_Float,
	F_R16G16B16A16_UNorm,
	F_R16G16B16A16_Uint,
	F_R16G16B16A16_SNorm,
	F_R16G16B16A16_Sint,
	F_R32G32_Typeless,
	F_R32G32_Float,
	F_R32G32_Uint,
	F_R32G32_Sint,


	F_R8G8B8A8_Typeless,
	F_R8G8B8A8_UNorm,
	F_R8G8B8A8_Uint,
	F_R8G8B8A8_SNorm,
	F_R8G8B8A8_Sint,
	F_R8G8B8A8_Float,

	F_D24_Unorm_S8_Uint,
	F_D32_Unorm	,




	F_FormatCount
};

static bool IsDepthStencilFormat(EFormat format)
{
	return format == F_D24_Unorm_S8_Uint;
}

static bool IsDepthOnlyFormat(EFormat format)
{
	return format == F_D32_Unorm;
}

static bool IsColorFormat(EFormat format)
{
	return format <= F_R16G16B16A16_Sint && format >= F_R32G32B32A32_Typeless;
}


enum ETextureType
{
	TT_Undefined,
	TT_Texture1D,
	TT_Texture2D,
	TT_Texture3D,
};

enum EAttachmentStoreOp
{
	ASO_Store,
	ASO_DontCare,
	ASO_None,
};

enum EAttachmentLoadOp
{
	ALO_Store,
	ALO_DontCare,
	ALO_None,
};

enum ESampleCount
{
	SC_1 = 1,
	SC_2 = 1<<1,
	SC_4 = 1<<2,
	SC_8 = 1<<3,
	SC_16 = 1<<4,
	SC_32 = 1<<5,
	SC_64 = 1<<6,
};

enum ESamplerFilter : uint8
{
	SF_NONE,// use default decide by Graphics API
	SF_Point,
	SF_Linear,
	SF_Anisotropic
};

enum ESamplerAddress :uint8
{
	SA_NONE,// use default decide by Graphics API
	SA_Clamp,
	SA_Wrap
};

enum class EShaderType : uint32
{
	eNone,
	eVertexShader,
	ePixelShader,
	eComputeShader,
	eGeometryShader
};
using EShaderTypeFlag = Flags<EShaderType>; 
using EShaderTypeFlagBits = EShaderType; 
template<>
struct FlagTraits<EShaderType> {
	constexpr static bool isBitMask = true;
};


enum class ECullMode
{
	CM_None,
	CM_Front,
	CM_Back,
};

enum class EFrontFace
{
	FF_CounterClockwise,
	FF_Clockwise,	
};

enum class EPolygonMode
{
	PM_Fill,
	PM_Point,
	PM_Line,
	PM_RectangleNV,
};

enum class EUniformUsage
{
	eUniform,
	eSampled, // texture
};

#endif // !RHI_DEFINITIONS_H
