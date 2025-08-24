#pragma once
#include"RHIResource\RHIResource.h"
#include"glad\glad.h"
#include"GLFW\glfw3.h"
#include"GLFW\glfw3native.h"


#ifndef RHI_OPENGL_BODY
#define RHI_OPENGL_BODY(clazz) friend class FRHIOpenGL3Dynamic;
#endif // !RHI_OPENGL_BODY


class FRHIOpenGL3Window :public FRHIWindow
{
public:
	FRHIOpenGL3Window(int width,int height,bool isFullScreen = false);
	virtual ~FRHIOpenGL3Window()override;
	virtual bool ShouldClose()override;
	virtual void PollEvents()override;
	virtual void SwapBuffers()override;

	virtual float32 GetRunningTime()override;

	GLFWwindow* GetWindowRef() { return window; }
private:
	GLFWwindow* window;

};

class FRHIOpenGL3VertexShader : public FRHIVertexShader
{
public:
	FRHIOpenGL3VertexShader()
		:FRHIVertexShader()
	{}
	virtual ~FRHIOpenGL3VertexShader()override;

public:
	GLuint shader;
};

class FRHIOpenGL3PixelShader : public FRHIPixelShader
{
public:
	FRHIOpenGL3PixelShader(){}
	virtual ~FRHIOpenGL3PixelShader()override;

public:
	GLuint shader;
};



class FRHIOpenGL3VertexBuffer : public FRHIBuffer
{
public:
	FRHIOpenGL3VertexBuffer(uint64 inSize,uint32 inStride,uint64 inCount,const void *inData)
		:FRHIBuffer(inSize,inStride,inCount,inData)
	{
		
	}
	~FRHIOpenGL3VertexBuffer()
	{

	}

	virtual void BufferData(const void*inData)override;
	virtual void CopyBuffer(const FRHIBuffer* buffer)override;
	virtual void ReleaseBuffer()override;
	virtual void Bind()override;


private:
	GLuint buffer;
};


class FRHIOpenGL3Renderpass : public FRHIRenderpass
{
public:
	FRHIOpenGL3Renderpass()
		:FRHIRenderpass()
	{

	}



	virtual ~FRHIOpenGL3Renderpass()override
	{
		framebuffer.reset();
	}

	
};

class FRHIOpenGL3Texture2D :public FRHITexture
{
public:

	RHI_OPENGL_BODY(FRHIOpenGL3Texture2D)

	explicit FRHIOpenGL3Texture2D(FTextureDescription desc)
		:FRHITexture(desc,TT_Texture2D)
	{
		
	}
	~FRHIOpenGL3Texture2D()override
	{
	}
	
	GLuint GetTexture()const
	{
		return this->texture;
	}

private:
	GLuint texture;
};

// 
class FRHIOpenGL3Framebuffer : public FRHIFramebuffer
{
public:
	RHI_OPENGL_BODY(FRHIOpenGL3Framebuffer)


	FRHIOpenGL3Framebuffer(int32 width,int32 height,EFramebufferAttachmentFlags eframebufferattachment)
		:FRHIFramebuffer(width,height,eframebufferattachment)
	{
		Init();
		
	}

	FRHIOpenGL3Framebuffer(FRHIFramebufferInitializer& initializer)
		:FRHIFramebuffer(initializer)
	{
		Init();
	}
	virtual void* GetColorAttachmentTexture()const override;
	
	virtual ~FRHIOpenGL3Framebuffer()override;

	

	GLuint FBO; // framebuffer object
	GLuint RBO; // renderbuffer object
	GLuint TBO; // color texture object
	GLuint DBO; // depth texture object

	
private:
	void Init();
};

struct FOpenGL3ShaderStateCache : public FShaderStateCache
{
	GLuint program;
};

class FRHIOpenGL3VertexArrayBuffer : public FRHIVertexArrayBuffer
{
public:
	RHI_OPENGL_BODY(FRHIOpenGL3VertexArrayBuffer)

	FRHIOpenGL3VertexArrayBuffer()
		:FRHIVertexArrayBuffer()
	{
		InitVAO();
	}
	FRHIOpenGL3VertexArrayBuffer(
		const void* inVertexData, uint64 inVertexCount, uint64 inVertexElementSize,
		const void* inIndexData, uint64 inIndexCount, uint64 inIndexElementSize
	)
		:FRHIVertexArrayBuffer(const_cast<void*>(inVertexData),inVertexCount,inVertexElementSize,
			const_cast<void*>(inIndexData),inIndexCount,inIndexElementSize)
	{
		InitVAO();
	}

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	virtual void BufferVertexData(void* inData, uint64 inVertexCount, uint64 inVertexElementSize)override;
	virtual void BufferIndexData(void* inData, uint64 inIndexCount, uint64 inIndexElementSize)override;
private:
	void InitVAO();
	void AssembleVertexArrayBuffer(GLuint VAO,FShaderInputLayout&layout);
};

class FRHIOpenGL3Uniformbuffer : public FRHIUniformbuffer
{
public:
	FRHIOpenGL3Uniformbuffer()
		:FRHIUniformbuffer()
	{
		ResetBuffer();
	}

	void ResetBuffer()
	{
		if (glIsBuffer(UBO))
		{
			glDeleteBuffers(1, &UBO);
		}
		glGenBuffers(1, &UBO);
	}

	virtual void BufferData(const void* data, uint64 size)override;
	virtual void BufferSubData(const void* data, uint64 offset, uint64 size)override;
	GLuint UBO;
private:
};