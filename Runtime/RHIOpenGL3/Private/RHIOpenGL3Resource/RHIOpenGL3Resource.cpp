#include"RHIOpenGL3Resource/RHIOpenGL3Resource.h"
#include"FOpenGL.h"
#include"RHIOpenGL3Dynamic.h"

FRHIOpenGL3Dynamic* GetOpenGL3RHI()
{
	return (FRHIOpenGL3Dynamic*)GetRHI().get();
}

FRHIOpenGL3Window::FRHIOpenGL3Window(int32 width,int32 height,bool isFullScreen)
	:FRHIWindow(glfw,width,height,isFullScreen)
{
	window = glfwCreateWindow(width, height, "JayEngine", NULL, NULL);
	glfwMakeContextCurrent(window);
}

FRHIOpenGL3Window::~FRHIOpenGL3Window()
{

}

bool FRHIOpenGL3Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void FRHIOpenGL3Window::PollEvents()
{
	glfwPollEvents();
}

void FRHIOpenGL3Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}

float32 FRHIOpenGL3Window::GetRunningTime()
{
	return glfwGetTime();
}

FRHIOpenGL3VertexShader::~FRHIOpenGL3VertexShader()
{
	
}


FRHIOpenGL3PixelShader::~FRHIOpenGL3PixelShader()
{
	
}


void FRHIOpenGL3VertexBuffer::BufferData(const void* inData)
{

}

void FRHIOpenGL3VertexBuffer::CopyBuffer(const FRHIBuffer* buffer)
{

}

void FRHIOpenGL3Framebuffer::Init()
{
	glGenFramebuffers(1, &FBO);
	glGenRenderbuffers(1, &RBO);

	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
	glBindRenderbuffer(GL_RENDERBUFFER, RBO);

	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH24_STENCIL8, GL_RENDERBUFFER, RBO);
	//std::cout << "FB : " << width << ' ' << height << '\n';
	
	// create texture about any attachments

	if (framebufferAttachments & EFramebufferAttachmentFlagBits::FA_Color)
	{
		/*if (!1) {
			glGenTextures(1, &TBO);
			glBindTexture(GL_TEXTURE_2D, TBO);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindTexture(GL_TEXTURE_2D, 0);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, TBO, 0);

			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				std::cout << "ERROR::POSTPROCESSOR: Failed to initialize FBO" << std::endl;

		}*/
		//else
		{
			// create color texture
			FRHITextureRef ref;

			FTextureDescription desc;
			desc
				.SetWidth(width)
				.SetHeight(height)
				.SetArraySize(1)
				.SetClearValueBinding(CVB_Color)
				.SetColorClearValue(initializer.clearColor)
				.SetFormat(F_R32G32B32A32_Float)
				.SetMinFilter(ESamplerFilter::SF_Linear)
				.SetMaxFilter(ESamplerFilter::SF_Linear)
				;
			auto* rhi = GetOpenGL3RHI();
			ref = rhi->CreateTexture2D(desc);

			FRHIOpenGL3Texture2D* color;
			color = rhi->ResourceCast(ref.get());
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, color->GetTexture(), 0);
			attachments.push_back(ref);

			FAttachmentReference attachmentRef;
			attachmentRef
				.SetEFramebufferAttachment(EFramebufferAttachmentFlagBits::FA_Color)
				.SetEAttachmentIndex(attachmentsReference.size())
				;
			attachmentsReference.push_back(attachmentRef);

			TBO = color->GetTexture();
			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				std::cout << "ERROR::POSTPROCESSOR: Failed to initialize FBO" << std::endl;
		}
	}
	// 模板暂时不能用
	if (framebufferAttachments & EFramebufferAttachmentFlagBits::FA_DepthStencil)
	{
		FTextureDescription desc;
		desc
			.SetWidth(width)
			.SetHeight(height)
			.SetArraySize(1)
			.SetClearValueBinding(CVB_DepthStencil)
			.SetDepthClearValue(initializer.clearDepth)
			.SetStencilClearValue(initializer.clearStencil)
			.SetFormat(F_D24_Unorm_S8_Uint)
			.SetMinFilter(SF_Linear)
			.SetMaxFilter(SF_Linear)
			;
		auto* rhi = GetOpenGL3RHI();
		FRHITextureRef ref;
		ref = rhi->CreateTexture2D(desc);
		FRHIOpenGL3Texture2D* depthStencilTexture = rhi->ResourceCast(ref.get());
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH24_STENCIL8, GL_TEXTURE_2D, depthStencilTexture->GetTexture(), 0);
		
		attachments.push_back(ref);

		FAttachmentReference attachmentRef;
		attachmentRef
			.SetEFramebufferAttachment(EFramebufferAttachmentFlagBits::FA_DepthStencil)
			.SetEAttachmentIndex(attachmentsReference.size())
			;
		attachmentsReference.push_back(attachmentRef);
	}

	if (framebufferAttachments & EFramebufferAttachmentFlagBits::FA_Depth)
	{
		FTextureDescription desc;
		desc
			.SetWidth(width)
			.SetHeight(height)
			.SetArraySize(1)
			.SetClearValueBinding(CVB_DepthStencil)
			.SetDepthClearValue(initializer.clearDepth)
			.SetFormat(F_D32_Unorm)
			.SetMinFilter(SF_Linear)
			.SetMaxFilter(SF_Linear)
			;
		auto* rhi = GetOpenGL3RHI();
		FRHITextureRef ref;
		ref = rhi->CreateTexture2D(desc);
		FRHIOpenGL3Texture2D* depthTexture = rhi->ResourceCast(ref.get());
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture->GetTexture(), 0);

		attachments.push_back(ref);

		FAttachmentReference attachmentRef;
		attachmentRef
			.SetEFramebufferAttachment(EFramebufferAttachmentFlagBits::FA_Depth)
			.SetEAttachmentIndex(attachmentsReference.size())
			;
		attachmentsReference.push_back(attachmentRef);

		DBO = depthTexture->GetTexture();

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
	}

}

void* FRHIOpenGL3Framebuffer::GetColorAttachmentTexture()const
{
	return (void*)TBO;
}

FRHIOpenGL3Framebuffer::~FRHIOpenGL3Framebuffer()
{
	for (auto& fb : attachments)
	{
		fb.reset();
	}
}


void FRHIOpenGL3VertexArrayBuffer::InitVAO()
{
	if (glIsVertexArray(VAO))
	{
		glDeleteVertexArrays(1, &VAO);
	}
	glGenVertexArrays(1, &VAO);
	
	auto& ctx = GetCurrentOpenGLContext();
	
	ctx.VAO = VAO;



	glBindVertexArray(VAO);
	


	BufferVertexData(vertexData, vertexCount, vertexElementSize);
	BufferIndexData(indexData, indexCount, indexElementSize);
	/*
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexCount*vertexElementSize, vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount*indexElementSize, indexData, GL_STATIC_DRAW);*/

	glBindVertexArray(0);

	AssembleVertexArrayBuffer(VAO, ctx.shaderInputLayout);

	//return;
	
}

void FRHIOpenGL3VertexArrayBuffer::BufferVertexData(void* inData, uint64 inVertexCount, uint64 inVertexElementSize)
{
	if (glIsBuffer(VBO))
	{
		glDeleteBuffers(1, &VBO);
	}

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, inVertexCount * inVertexElementSize, inData, GL_STATIC_DRAW);
	//std::cout <<"Vertices Size : " << inVertexCount * inVertexElementSize << '\n';

}

void FRHIOpenGL3VertexArrayBuffer::BufferIndexData(void* inData, uint64 inIndexCount, uint64 inIndexElementSize)
{
	if (glIsBuffer(EBO))
	{
		glDeleteBuffers(1, &EBO);
	}


	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, inIndexCount * inIndexElementSize, inData, GL_STATIC_DRAW);
	//std::cout << "Indices Size : " << inIndexCount * inIndexElementSize << '\n';

}

void FRHIOpenGL3VertexArrayBuffer::AssembleVertexArrayBuffer(GLuint vao, FShaderInputLayout& layout)
{
	uint32 offset;
	glBindVertexArray(VAO);
	for (int32 i = 0; i < layout.shaderInputs.size(); ++i)
	{
		auto& part = layout.shaderInputs[i];
		glEnableVertexAttribArray(i);
		//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glVertexAttribPointer(i, part.paramterCount, GL_FLOAT, GL_FALSE, part.elementSize, (void*)part.offset);
	}
	glBindVertexArray(0);
}

void FRHIOpenGL3Uniformbuffer::BufferData(const void* data, uint64 size)
{
	glBindBuffer(GL_UNIFORM_BUFFER, UBO);

	glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW);

	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void FRHIOpenGL3Uniformbuffer::BufferSubData(const void* data, uint64 offset, uint64 size)
{
	glBindBuffer(GL_UNIFORM_BUFFER, UBO);

	glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);

	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}