#pragma once
#include"glad\glad.h"
#include"GLFW\glfw3.h"
#include"CoreDevelopMarco.h"
#include"Containers\Containers.h"

#include"RHICommon.h"
#include"RHIResource\RHIResource.h"
#include"RHIOpenGL3Resource\RHIOpenGL3Resource.h"

enum EOpenGLShaderType
{
	OST_VertexShader,
	OST_PixelShader,// frag
	OST_ComputeShader,
};

enum EOpenGLResourceType
{
	ORT_Unknow,
	ORT_VertexShader,// trival
	ORT_PixelShader,// frag shader // trival
	ORT_VertexBuffer,// VBO =
	ORT_VertexArrayBuffer,// VAO
	ORT_Program,
	ORT_IndexBuffer,// EBO
	ORT_UniformBuffer,
	ORT_Texture2D,
	ORT_Framebuffer,
	ORT_Renderbuffer,
};

template<EOpenGLResourceType resouceType>
class FOpenGLResource;


struct FOpenGLFormatInfo
{
	alignas(64) GLenum internalFormat; // internal
	uint64 size;
	alignas(64) GLenum internalFormatSRGB; // internal
	alignas(64) GLenum format;
	alignas(64) GLenum type;
};

class FOpenGL
{
public:
	FOpenGL();
	static uint64 GetFormatSize(EFormat format);
	static FOpenGLFormatInfo GetFormatInfo(EFormat format);
	static GLenum TranslateCullMode(ECullMode);
	static GLenum TranslatePolygonMode(EPolygonMode);
	static GLenum TranslateDepthStencilFormat(EFormat);
	static GLenum TranslateSamplerFilter(ESamplerFilter);
	static GLenum TranslatePrimitiveTopology(EPrimitiveTopologyType);
	// wrap in opengl
	static GLenum TranslateSamplerAddressMode(ESamplerAddress);
	static GLenum TranslateFormat(EFormat format);

	static void BindFramebuffer(GLuint resource);
	static void BindRenderbuffer(GLuint resource);
	static void BindVertexArrayBuffer(GLuint resource);
	static void UseProgram(GLuint program);

	static void TextureToBufferf(int textureId, int x, int y, int width, int height, float* buffer);

	static GLenum GetGLEnum(EOpenGLResourceType type);
	static void CreateResource(GLuint* resource, size_t count, GLenum type);
	static void DestroyResource(GLuint* resource, size_t count, GLenum type);
	static void CheckCompileErrors(GLuint shader, FString type);
	static void LinkProgram(FShaderStateCache* cache, FShaderState& state);
	static void UniformBlockBinding(GLuint shader, const char* uniformName, GLuint binding);
	static void BindBufferRange(GLuint binding, GLuint buffer, uint64 offset, uint64 size);
	static void BindTexture(GLuint textureSlot,GLuint texture);
private:
	static void CreateShader(GLuint* resource, GLenum shaderType);
	static void CreateBuffer(GLuint* resource, size_t count);
};


class FOpenGLContext
{
public:
	
	inline static GLint maxNumOfUniformBindingLocationInVertex = 0;
	inline static GLint maxNumOfUniformBindingLocationInFragment = 0;
	inline static GLint maxNumOfUniformBindingLocationInGeometry = 0;
public:
	static FOpenGLContext gOpenGLContext;
	FOpenGLContext();
	FOpenGLContext(const FOpenGLContext&rhs) = delete;
	~FOpenGLContext(){}

	// 所有的状态设置包含一个目标值和当前值
	// 目标值通过FRHI 的 set graphicspipeline | begin renderpass 设置
	// 只有当目标值与当前值不同时才会调用FOpenGL中类似bindframebuffer setshader 等状态切换的方法
	GLuint Program;
	GLuint currentProgram;
	GLuint FBO;
	//GLuint currentFBO;
	GLuint RBO;
	GLuint currentRBO;
	GLenum currentPrimitiveTopology;

	// uniform buffer 的绑定和解绑信息

	int32 uniformbufferBindingCount;
	TArray<int32> uniformBindingIndices;
	
	
	// 一些状态，opengl资源在创建后会自动绑定，以下内容为保存的状态

	//通过CreateGraphicsPipeline | SetGraphicsPipeline | begin renderpass 设置
	FShaderInputLayout shaderInputLayout;// for assemble vertex shader
	FRasterizationState rasterizationState;
	FShaderState shaderState;
	FOpenGL3ShaderStateCache* shaderCache;
	FRHIUniformState* uniformState;
	//通过createVertexArraybuffer或者再通过VAO提交渲染时设置
	GLuint VAO;
	GLuint currentVAO;
	//以下VBO与EBO的设计理念与VAO一样
	//通过创建buffer或提交渲染时设定
	GLuint VBO;
	GLuint currentVBO;
	GLuint EBO;
	GLuint currentEBO;
};

inline static FOpenGLContext& GetCurrentOpenGLContext()
{
	return FOpenGLContext::gOpenGLContext;
}

template<EOpenGLResourceType resouceType = ORT_Unknow>
class FOpenGLResource // 弃用
{
public:

	void Init()
	{
		type = FOpenGL::GetGLEnum(resouceType);
		FOpenGL::CreateResource(&resource, 1, type);
	}

	FOpenGLResource()
	{
		
	}
	~FOpenGLResource()
	{

	}
	GLuint resource;
	GLenum type;
};