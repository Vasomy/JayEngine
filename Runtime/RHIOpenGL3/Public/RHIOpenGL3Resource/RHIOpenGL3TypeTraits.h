#pragma once
#include"RHIResource\RHITypeTraits.h"
#include"RHIOpenGL3Resource.h"

template<typename T>
struct RHIOpenGL3TypeTraits;

template<>
struct RHIOpenGL3TypeTraits<FRHIUniformbuffer>
{
	using type = FRHIOpenGL3Uniformbuffer;
};

template<>
struct RHIOpenGL3TypeTraits<FRHITexture>
{
	using type = FRHIOpenGL3Texture2D;
};

template<>
struct RHIOpenGL3TypeTraits<FRHIFramebuffer>
{
	using type = FRHIOpenGL3Framebuffer;
};

template<>
struct RHIOpenGL3TypeTraits<FRHIWindow>
{
	using type = FRHIOpenGL3Window;
};

template<>
struct RHIOpenGL3TypeTraits<FRHIVertexShader>
{
	using type = FRHIOpenGL3VertexShader;
};

template<>
struct RHIOpenGL3TypeTraits<FRHIPixelShader>
{
	using type = FRHIOpenGL3PixelShader;
};

template<>
struct RHIOpenGL3TypeTraits<FShaderStateCache>
{
	using type = FOpenGL3ShaderStateCache;
};

template<>
struct RHIOpenGL3TypeTraits<FRHIVertexArrayBuffer>
{
	using type = FRHIOpenGL3VertexArrayBuffer;
};

