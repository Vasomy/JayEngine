#include "RHIOpenGL3Dynamic.h"
void FRHIOpenGL3Dynamic::Init()
{
	// init graphcis api
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void FRHIOpenGL3Dynamic::PostInit()
{
	glfwSwapInterval(1);

	// load glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	glGetIntegerv(GL_MAX_VERTEX_UNIFORM_BLOCKS, &FOpenGLContext::maxNumOfUniformBindingLocationInVertex);
	glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_BLOCKS, &FOpenGLContext::maxNumOfUniformBindingLocationInFragment);
	glGetIntegerv(GL_MAX_GEOMETRY_UNIFORM_BLOCKS, &FOpenGLContext::maxNumOfUniformBindingLocationInGeometry);
	FOpenGLContext::gOpenGLContext.uniformBindingIndices.resize(FOpenGLContext::maxNumOfUniformBindingLocationInVertex);

}

void FRHIOpenGL3Dynamic::Shutdown()
{
}

void FRHIOpenGL3Dynamic::MakeCurrentWindowContext(FRHIWindowRef window)
{
	auto dwindow = ResourceCast(window.get());
	glfwMakeContextCurrent(dwindow->GetWindowRef());
}

FRHIWindowRef FRHIOpenGL3Dynamic::CreateWindowByRHI(int32 width, int32 height, bool isFullScreen)
{
	auto retWindow = FRHIWindowRef();

	retWindow.reset(
		new FRHIOpenGL3Window(width,height,isFullScreen)
	);
	return std::move(retWindow);
}

FRHIVertexArrayBufferRef FRHIOpenGL3Dynamic::CreateVertexBufferArray()
{
	FRHIVertexArrayBufferRef ref;
	ref
		.reset(new FRHIOpenGL3VertexArrayBuffer());
	auto& ctx = GetCurrentOpenGLContext();
	auto* ptr =ResourceCast<FRHIOpenGL3VertexArrayBuffer>(ref.get());
	ctx.VAO = ptr->VAO;
	return ref;
}

FRHIVertexArrayBufferRef FRHIOpenGL3Dynamic::CreateVertexBufferArray(
	const void* inVertexData,
	uint64 inVertexCount, uint64 inVertexElementSize,
	const void* inIndexData,
	uint64 inIndexCount, uint64 inIndexElementSize)
{
	FRHIVertexArrayBufferRef ref;
	ref.reset(
		new FRHIOpenGL3VertexArrayBuffer(inVertexData, inVertexCount, inVertexElementSize,
			inIndexData, inIndexCount, inIndexElementSize)
	);
	auto& ctx = GetCurrentOpenGLContext();
	auto* ptr = ResourceCast<FRHIOpenGL3VertexArrayBuffer>(ref.get());
	ctx.VAO = ptr->VAO;
	return ref;
}

FRHIUniformbufferRef FRHIOpenGL3Dynamic::CreateUniformbuffer(uint64 size)
{
	FRHIUniformbufferRef ref;
	ref.reset(new FRHIOpenGL3Uniformbuffer());
	auto* ptr = ResourceCast(ref.get());
	ptr->BufferData(nullptr, size);
	return ref;
}

void FRHIOpenGL3Dynamic::UpdateUniformbuffer(FRHIUniformbuffer*target,const void* data, uint64 offset, uint64 size)
{
	auto* ptr = ResourceCast(target);
	ptr->BufferSubData(data, offset, size);
}

FRHIVertexShaderRef FRHIOpenGL3Dynamic::CreateVertexShader(TArray<char8>code)
{
	FRHIVertexShaderRef vertexShader;
	vertexShader.reset(
		new FRHIOpenGL3VertexShader()
	);
	auto* ptr = ResourceCast(vertexShader.get());
	ptr->shader = glCreateShader(GL_VERTEX_SHADER);
	const char8* codes = code.data();
	//std::cout << codes << '\n';
	glShaderSource(ptr->shader, 1, &codes, NULL);
	glCompileShader(ptr->shader);
	FOpenGL::CheckCompileErrors(ptr->shader, "Vertex");
	return vertexShader;
}

FRHIPixelShaderRef FRHIOpenGL3Dynamic::CreatePixelShader(TArray<char8>code)
{
	FRHIPixelShaderRef pixelShader;
	pixelShader.reset(
		new FRHIOpenGL3PixelShader()
	);
	auto* ptr = ResourceCast(pixelShader.get());
	ptr->shader = glCreateShader(GL_FRAGMENT_SHADER);
	const char8* codes = code.data();
	//std::cout << codes << '\n';
	glShaderSource(ptr->shader, 1, &codes, NULL);
	glCompileShader(ptr->shader);
	FOpenGL::CheckCompileErrors(ptr->shader, "Pixel/Fragment");
	return pixelShader;
}

FRHITextureRef FRHIOpenGL3Dynamic::CreateTexture2D(FTextureDescription& desc,const void *data)
{
	FRHITextureRef ref;
	ref.reset(new FRHIOpenGL3Texture2D(desc));
	auto* ptr = ResourceCast<FRHIOpenGL3Texture2D*>(ref.get());


	glGenTextures(1, &ptr->texture);


	glBindTexture(GL_TEXTURE_2D,ptr->texture);
	// maybe we need check that is data's length equal width*height
	if(data!=nullptr)
	{
		//check data size
		uint64 size = _msize(const_cast<void*>(data));
		uint64 elementSize = FOpenGL::GetFormatSize(desc.format);

		uint64 length = size/elementSize;

		if (length != desc.width * desc.height)
		{
			LOG_WARRING_INFO(FRHIOpenGL3Dynamic::CreateTexture2D, "Input data size not fit texture size!");
		}

	}

	const auto& formatInfo = FOpenGL::GetFormatInfo(desc.format);
	glTexImage2D(GL_TEXTURE_2D, 0, formatInfo.internalFormat,desc.width,desc.height,0,formatInfo.format,formatInfo.type,data);
	if(desc.uAddressMode !=SA_NONE && desc.vAddressMode !=SA_NONE)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, FOpenGL::TranslateSamplerAddressMode(desc.uAddressMode));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, FOpenGL::TranslateSamplerAddressMode(desc.vAddressMode));
	}
	if (desc.minFilter != SF_NONE && desc.maxFilter != SF_NONE)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FOpenGL::TranslateSamplerFilter(desc.minFilter));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FOpenGL::TranslateSamplerFilter(desc.maxFilter));
	}
	glBindTexture(GL_TEXTURE_2D, 0);

	return ref;
}

FRHIGraphicsPipelineStateRef FRHIOpenGL3Dynamic::CreateGraphicsPipelineState(FRHIGraphicsPipelineInitializer& initializer)
{
	FRHIGraphicsPipelineStateRef ret;
	ret.reset(new FRHIGraphicsPipelineState(initializer));
	ret->initializer.shaderStateCache.reset(new FOpenGL3ShaderStateCache());
	FOpenGL::LinkProgram(ret->initializer.shaderStateCache.get(), ret->initializer.shaderState);
	
	auto* openglShaderCache = ResourceCast(ret->initializer.shaderStateCache.get());


	for (auto& attri : ret->initializer.uniformState.attributions)
	{
		if (attri.usage == EUniformUsage::eUniform) {
			attri
				.SetBindingFunction(
					[&]()
					{
						auto* oub = ResourceCast(attri.uniformbuffer);
						FOpenGL::BindBufferRange(attri.binding, oub->UBO, 0, attri.size);
					}
			);
			attri
				.SetUnBindingFunction(
					[&]()
					{
						FOpenGL::BindBufferRange(attri.binding, 0, 0, 0);
					}
				)
				;
			FOpenGL::UniformBlockBinding(openglShaderCache->program, attri.name.data(), attri.binding);
			
		}
		else if (attri.usage == EUniformUsage::eSampled)
		{
			GLuint id = glGetUniformLocation(openglShaderCache->program, attri.name.data());
			
			attri.textureBinding = id;
			attri
				.SetBindingFunction(
				[&]
				{
					auto* pTex = ResourceCast<FRHIOpenGL3Texture2D>(attri.texture);
					glUniform1i(attri.textureBinding, attri.binding);
					FOpenGL::BindTexture(attri.binding, pTex->GetTexture());
				}
			);
			attri
				.SetUnBindingFunction(
				[&]
				{
					FOpenGL::BindTexture(attri.binding, 0);
				}
			);
		}
	}
	
	SetGraphicsPipelineState(ret);
	return ret;
}

FRHIRenderpassRef FRHIOpenGL3Dynamic::CreateRenderpass(FRHIFramebufferInitializer& initializer)
{
	FRHIRenderpassRef ref;
	ref.reset(new FRHIOpenGL3Renderpass());
	ref->framebuffer = CreateFramebuffer(initializer);
	return ref;
}

FRHIFramebufferRef FRHIOpenGL3Dynamic::CreateFramebuffer(int32 width, int32 height, EFramebufferAttachmentFlags flags)
{
	FRHIFramebufferRef ref;
	ref.reset(new FRHIOpenGL3Framebuffer(width, height, flags));
	return ref;
}

FRHIFramebufferRef FRHIOpenGL3Dynamic::CreateFramebuffer(FRHIFramebufferInitializer& initializer)
{
	FRHIFramebufferRef ref;
	ref.reset(new FRHIOpenGL3Framebuffer(initializer));
	return ref;
}

void FRHIOpenGL3Dynamic::ReadFramebufferPixels(FRHIFramebuffer* framebuffer, EFramebufferAttachmentFlagBits targetAttachment, 
	int32 x, int32 y, int32 width, int32 height,
	EFormat frameFormat, void* outValue)
{
	auto formatInfo = FOpenGL::GetFormatInfo(frameFormat);
	auto format = formatInfo.format;
	auto type = formatInfo.type;
	auto* oglFb = ResourceCast(framebuffer);
	
	if (targetAttachment == EFramebufferAttachmentFlagBits::FA_Color)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, oglFb->FBO);
		glReadPixels(x, y, width, height, format, type, outValue);
		glBindFramebuffer(GL_FRAMEBUFFER,0);
	}
}


void FRHIOpenGL3Dynamic::SetGraphicsPipelineState(FRHIGraphicsPipelineStateRef& graphicsPipelineState)
{
	auto& ctx = GetCurrentOpenGLContext();
	auto& initializer = graphicsPipelineState->initializer;
	
	auto* openglShaderCache = ResourceCast(initializer.shaderStateCache.get());

	ctx.Program = openglShaderCache->program;
	ctx.shaderState = initializer.shaderState;
	ctx.shaderInputLayout = initializer.shaderInput;
	ctx.shaderCache = ResourceCast<FOpenGL3ShaderStateCache>(initializer.shaderStateCache.get());
	ctx.rasterizationState = initializer.rasterizationSate;
	ctx.currentPrimitiveTopology = FOpenGL::TranslatePrimitiveTopology(initializer.primitiveTopology);


	if (ctx.rasterizationState.cullMode != ECullMode::CM_None)
	{
		GLenum cullMode = FOpenGL::TranslateCullMode(ctx.rasterizationState.cullMode);
		glEnable(GL_CULL_FACE);
		glCullFace(cullMode);
		
	}
	if (ctx.rasterizationState.enableDetphTest)
	{
		/*glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);*/
	}
	ctx.uniformbufferBindingCount = 0;
	
	if (ctx.currentProgram != ctx.Program)
	{
		ctx.currentProgram = ctx.Program;
		FOpenGL::UseProgram(ctx.currentProgram);
		//std::cout << ctx.currentProgram << '\n';
	}
	
	for (auto& attri : initializer.uniformState.attributions)
	{
		auto* oub = ResourceCast(attri.uniformbuffer);
		if (attri.usage == EUniformUsage::eUniform) 
		{
			attri.bindFunc();
		}
		else

		{
			auto* tex = ResourceCast<FRHIOpenGL3Texture2D>(attri.texture);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, tex->texture);
			glUniform1i(glGetUniformLocation(ctx.Program, attri.name.data()), 0);
		}
		ctx.uniformBindingIndices[ctx.uniformbufferBindingCount] = attri.binding;
		ctx.uniformbufferBindingCount++;
	}
	ctx.uniformState = &initializer.uniformState;
	

}

void FRHIOpenGL3Dynamic::BeginRenderpass(FRHIRenderpassRef& renderpass)
{
	auto* framebuffer = ResourceCast<FRHIOpenGL3Framebuffer>(renderpass->framebuffer.get());
	

	auto& ctx = GetCurrentOpenGLContext();
	
	ctx.FBO = framebuffer->FBO;
	
	FOpenGL::BindFramebuffer(ctx.FBO);
	
	GLenum clearTarget = 0;

	if (framebuffer->HaveColorAttachment())
	{
		auto clearColor = renderpass->GetClearColor();

		glClearColor(clearColor.x,clearColor.y,clearColor.z,clearColor.w);
		clearTarget |= GL_COLOR_BUFFER_BIT;
	}
	auto clearDSV = renderpass->GetClearDepthStencil();
	if (framebuffer->HaveDepthAttachment())
	{
		glClearDepth(1.0f);//
		clearTarget |= GL_DEPTH_BUFFER_BIT;
		glEnable(GL_DEPTH_TEST);
		//std::cout << clearDSV.depth << '\n';
	}
	if (framebuffer->HaveStencilAttachment())
	{
		glClearStencil(clearDSV.stencil);
		clearTarget |= GL_STENCIL_BUFFER_BIT;
	}
	glClear(clearTarget);
}

void FRHIOpenGL3Dynamic::EndRenderpass()
{
	FOpenGL::BindFramebuffer(0);

	auto& ctx = GetCurrentOpenGLContext();
	// unbind uniformbuffer
	//for (int i = 0; i < ctx.uniformState->attributions.size(); ++i)
	for(auto&attri:ctx.uniformState->attributions)
	{
		//FOpenGL::BindBufferRange(ctx.uniformBindingIndices[i], 0, 0, 0);
		attri.unbindFunc();
	}
}

void FRHIOpenGL3Dynamic::RHIDrawIndexed(FRHIVertexArrayBuffer* vao)
{
	SetUpRenderState();
	
	auto& ctx = GetCurrentOpenGLContext();
	auto* ptr = ResourceCast<FRHIOpenGL3VertexArrayBuffer>(vao);
	FOpenGL::BindVertexArrayBuffer(ptr->VAO);

	glDrawElements(ctx.currentPrimitiveTopology, ptr->indexCount, GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);
}

void FRHIOpenGL3Dynamic::RHIDrawIndexed(FRHIBuffer* vBuffer, FRHIBuffer* iBuffer)
{

}
// 
void FRHIOpenGL3Dynamic::SetUpRenderState()
{
	auto& ctx = GetCurrentOpenGLContext();

	//glEnable(GL_DEPTH_TEST);
}

void FRHIOpenGL3Dynamic::EndUpRenderState()
{
	FOpenGL::UseProgram(0);
	FOpenGL::BindFramebuffer(0);
	FOpenGL::BindVertexArrayBuffer(0);
}