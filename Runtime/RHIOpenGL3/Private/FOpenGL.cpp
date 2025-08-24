#include"FOpenGL.h"
#include<iostream>

#include"RHIOpenGL3Resource\RHIOpenGL3Resource.h"
#include"Log.h"


TArray<FOpenGLFormatInfo> gFormatInfos;
FOpenGLContext FOpenGLContext::gOpenGLContext = FOpenGLContext();

void _AddFormatInfo(EFormat eFormat,GLenum internalFormat,uint32 size,GLenum internalFormatSRGB,GLenum format,GLenum type)
{
	gFormatInfos[static_cast<uint32>(eFormat)] = { internalFormat,size,internalFormatSRGB,format,type };
}

FOpenGLContext::FOpenGLContext()
{
	gFormatInfos.resize(EFormat::F_FormatCount);
	
	_AddFormatInfo(EFormat::F_D24_Unorm_S8_Uint, GL_DEPTH24_STENCIL8, 4,GL_NONE,GL_DEPTH_STENCIL,GL_FLOAT);
	_AddFormatInfo(EFormat::F_D32_Unorm, GL_DEPTH_COMPONENT32, 4,GL_DEPTH_COMPONENT32,GL_DEPTH_COMPONENT,GL_UNSIGNED_BYTE);
	
	
	_AddFormatInfo(EFormat::F_R16G16B16A16_Float, GL_RGBA16F, 8, GL_RGBA16F, GL_RGBA, GL_HALF_FLOAT);;
	_AddFormatInfo(EFormat::F_R16G16B16A16_Sint, GL_RGBA16I, 8,GL_RGBA16I,GL_RGBA_INTEGER,GL_SHORT);
	_AddFormatInfo(EFormat::F_R16G16B16A16_Uint, GL_RGBA16UI, 8,GL_RGBA16UI,GL_RGBA_INTEGER,GL_UNSIGNED_SHORT);
	_AddFormatInfo(EFormat::F_R16G16B16A16_SNorm, GL_RGBA16, 8,GL_RGBA16,GL_RGBA,GL_SHORT);
	// 不支持unorm
	_AddFormatInfo(EFormat::F_R16G16B16A16_UNorm, GL_RGBA16, 8,GL_RGBA16,GL_RGBA,GL_UNSIGNED_SHORT);
	_AddFormatInfo(EFormat::F_R16G16B16A16_Typeless, GL_RGBA16, 8,GL_RGBA16,GL_RGBA,GL_SHORT);

	_AddFormatInfo(EFormat::F_R32G32B32A32_Float, GL_RGBA32F, 16,GL_RGBA32F,GL_RGBA,GL_FLOAT);
	_AddFormatInfo(EFormat::F_R32G32B32A32_Sint, GL_RGBA32I, 16,GL_RGBA32I,GL_RGBA_INTEGER,GL_INT);
	_AddFormatInfo(EFormat::F_R32G32B32A32_Uint, GL_RGBA32UI, 16,GL_RGBA32UI,GL_RGBA_INTEGER,GL_UNSIGNED_INT);
	// 注意在OpenGL3下不支持  R32G32B32A32 SNorm & UNorm
	_AddFormatInfo(EFormat::F_R32G32B32A32_SNorm, GL_RGBA32F,16, GL_RGBA32F,GL_RGBA,GL_FLOAT);
	_AddFormatInfo(EFormat::F_R32G32B32A32_UNorm, GL_RGBA32F,16,GL_RGBA32F,GL_RGBA,GL_FLOAT);
	
	_AddFormatInfo(EFormat::F_R32G32B32A32_Typeless, GL_RGBA32F, 16, GL_RGBA32F, GL_RGBA, GL_FLOAT);
	
	_AddFormatInfo(EFormat::F_R8G8B8A8_Sint, GL_RGBA8I, 4,GL_RGBA8I,GL_RGBA_INTEGER,GL_BYTE);
	_AddFormatInfo(EFormat::F_R8G8B8A8_Uint, GL_RGBA8UI, 4,GL_RGBA8UI,GL_RGBA_INTEGER,GL_UNSIGNED_BYTE);
	_AddFormatInfo(EFormat::F_R8G8B8A8_Float, GL_RGBA8, 4, GL_SRGB8_ALPHA8,GL_RGBA,GL_UNSIGNED_BYTE);
	_AddFormatInfo(EFormat::F_R8G8B8A8_SNorm, GL_RGBA8, 4, GL_SRGB8_ALPHA8, GL_RGBA, GL_UNSIGNED_BYTE);
	_AddFormatInfo(EFormat::F_R8G8B8A8_UNorm, GL_RGBA8, 4, GL_SRGB8_ALPHA8, GL_RGBA, GL_UNSIGNED_BYTE);

	_AddFormatInfo(EFormat::F_R32G32B32_Float, GL_RGB32F,12,GL_RGB32F,GL_RGB,GL_FLOAT);
	_AddFormatInfo(EFormat::F_R32G32B32_Sint, GL_RGB32I,12,GL_RGB32I,GL_RGB,GL_INT);
	_AddFormatInfo(EFormat::F_R32G32B32_Uint, GL_RGB32UI,12,GL_RGB32UI,GL_RGB,GL_UNSIGNED_INT);

	_AddFormatInfo(EFormat::F_R32G32B32_UNorm, GL_RGB32F, 12, GL_RGB32F, GL_RGB, GL_FLOAT);
	_AddFormatInfo(EFormat::F_R32G32B32_SNorm, GL_RGB32F, 12, GL_RGB32F, GL_RGB, GL_FLOAT);

	_AddFormatInfo(EFormat::F_R32G32_Typeless, GL_RG32F,8,GL_RG32F,GL_RG,GL_FLOAT);
	_AddFormatInfo(EFormat::F_R32G32_Float, GL_RG32F, 8, GL_RG32F, GL_RG, GL_FLOAT);
	_AddFormatInfo(EFormat::F_R32G32_Sint, GL_RG32I,8,GL_RG32I,GL_RG,GL_INT);
	_AddFormatInfo(EFormat::F_R32G32_Uint, GL_RG32UI,8,GL_RG32UI,GL_RG,GL_UNSIGNED_INT);

	

}

GLenum FOpenGL::GetGLEnum(EOpenGLResourceType type)
{
	GLenum glenum = 0;
	switch (type)
	{
	case ORT_Unknow:
		glenum = 0;
		break;
	case ORT_VertexShader:
		glenum = GL_VERTEX_SHADER;
		break;
	case ORT_PixelShader:
		glenum = GL_FRAGMENT_SHADER;
		break;
	case ORT_VertexBuffer:
		glenum = GL_ARRAY_BUFFER;
		break;
	case ORT_IndexBuffer:
		glenum = GL_ELEMENT_ARRAY_BUFFER;
		break;
	case ORT_UniformBuffer:
		glenum = GL_UNIFORM_BUFFER;
		break;
	case ORT_Texture2D:
		glenum = GL_TEXTURE_2D;
		break;
	case ORT_VertexArrayBuffer:
		glenum = GL_VERTEX_ARRAY;
		break;
	default:
		break;
	}
	return glenum;
}

GLenum FOpenGL::TranslatePrimitiveTopology(EPrimitiveTopologyType type)
{
	switch (type)
	{
	case PPT_Unknow:
		return GL_TRIANGLES;
		break;
	case PPT_Triangle:
		return GL_TRIANGLES;
		break;
	case PPT_TriangleStrip:
		return GL_TRIANGLE_STRIP;
		break;
	case PPT_TriangleFan:
		return GL_TRIANGLE_FAN;
		break;
	case PPT_Point:
		return GL_POINT;
		break;
	case PPT_Line:
		return GL_LINE;
		break;
	case PPT_LineStrip:
		return GL_LINE_STRIP;
		break;
	case PPT_LineLoop:
		return GL_LINE_LOOP;
		break;
	default:
		return GL_TRIANGLES;
		break;
	}
}

void FOpenGL::CheckCompileErrors(GLuint shader, FString type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n ------------------------------------------------------- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

void FOpenGL::CreateResource(GLuint* resource, size_t count, GLenum type)
{
	if (type == 0)
	{
		std::cout << MAKE_ERROR_INFO(FOpenGL::CreateResource,"Failed to create resource because resource type is not legal!\n");
		return;
	}
}

void FOpenGL::LinkProgram(FShaderStateCache* cache, FShaderState& state)
{
	// opengl shader cache -> osc
	auto* osc = reinterpret_cast<FOpenGL3ShaderStateCache*>(cache);
	osc->program = glCreateProgram();
	//std::cout << state.shaderTypeFlags.mask_ << '\n';
	if (state.shaderTypeFlags & EShaderType::eVertexShader)
	{
		auto* openglVertexShader = static_cast<FRHIOpenGL3VertexShader*>(state.vertexShader.get());
		glAttachShader(osc->program, openglVertexShader->shader);
	}
	if (state.shaderTypeFlags & EShaderTypeFlagBits::ePixelShader)
	{
		auto* openglPixelShader = reinterpret_cast<FRHIOpenGL3PixelShader*>(state.pixelShader.get());
		glAttachShader(osc->program, openglPixelShader->shader);
	}
	glLinkProgram(osc->program);
	osc->isCached = true;
	FOpenGL::CheckCompileErrors(osc->program, "PROGRAM");

}

// private
void FOpenGL::CreateShader(GLuint* resource, GLenum type)
{
	*resource = glCreateShader(type);
}

GLenum FOpenGL::TranslateDepthStencilFormat(EFormat format)
{
	if (!IsDepthStencilFormat(format))
	{
		std::cout << MAKE_ERROR_INFO(FOpenGL::TranslateDepthStencilFormat, "format is not depth stencil format or depth format");
		return 0;
	}
	if (format == EFormat::F_D24_Unorm_S8_Uint)
	{
		return GL_DEPTH24_STENCIL8;
	}
	if (format == EFormat::F_D32_Unorm)
	{
		return GL_DEPTH_COMPONENT32F;
	}
	return 0;
}

GLenum FOpenGL::TranslateCullMode(ECullMode cullMode)
{
	switch (cullMode)
	{
	case ECullMode::CM_None:
		return NULL;
		break;
	case ECullMode::CM_Front:
		return GL_FRONT;
		break;
	case ECullMode::CM_Back:
		return GL_BACK;
		break;
	default:
		break;
	}
	return NULL;
}

GLenum FOpenGL::TranslatePolygonMode(EPolygonMode polygonMode)
{
	switch (polygonMode)
	{
	case EPolygonMode::PM_Fill:
		return GL_FILL;
		break;
	case EPolygonMode::PM_Point:
		return GL_POINT;
		break;
	case EPolygonMode::PM_Line:
		return GL_LINE;
		break;
	case EPolygonMode::PM_RectangleNV:
		return GL_FILL;
		break;
	default:
		break;
	}
	return NULL;
}

GLenum FOpenGL::TranslateSamplerAddressMode(ESamplerAddress addressmode)
{
	switch (addressmode)
	{
	case SA_NONE:
		return NULL;
		break;
	case SA_Clamp:
		return GL_CLAMP;
		break;
	case SA_Wrap:
		return GL_REPEAT;
		break;
	default:
		return NULL;
		break;
	}
}

GLenum FOpenGL::TranslateSamplerFilter(ESamplerFilter filter)
{
	switch (filter)
	{
	case SF_NONE:
		break;
	case SF_Point:
		return GL_POINT;
		break;
	case SF_Linear:
		return GL_LINEAR;
		break;
	case SF_Anisotropic:
		float fLargest;
		
		// 暂未实现各向异性
		return NULL;
		break;
	default:
		break;
	}
}

GLenum FOpenGL::TranslateFormat(EFormat format)
{
	return gFormatInfos[static_cast<uint32>(format)].format;
}

uint64 FOpenGL::GetFormatSize(EFormat format)
{
	return gFormatInfos[static_cast<uint32>(format)].size;
}

FOpenGLFormatInfo FOpenGL::GetFormatInfo(EFormat format)
{
	return gFormatInfos[static_cast<uint32>(format)];
}

void FOpenGL::UseProgram(GLuint program)
{
	glUseProgram(program);
}

void FOpenGL::BindFramebuffer(GLuint framebuffer)
{
	glBindFramebuffer(GL_FRAMEBUFFER,framebuffer);
}

void FOpenGL::BindVertexArrayBuffer(GLuint vao)
{
	glBindVertexArray(vao);
}

void FOpenGL::UniformBlockBinding(GLuint shader, const char* uniformName, GLuint binding)
{
	GLuint index = glGetUniformBlockIndex(shader, uniformName);
	glUniformBlockBinding(shader, index, binding);
}

void FOpenGL::BindBufferRange(GLuint binding, GLuint buffer, uint64 offset, uint64 size)
{
	glBindBufferRange(GL_UNIFORM_BUFFER, binding, buffer, offset, size);
}

static GLenum GLTextureBindingName[32] =
{
	GL_TEXTURE0,
	GL_TEXTURE1,
	GL_TEXTURE2,
	GL_TEXTURE3,
	GL_TEXTURE4,
	GL_TEXTURE5,
	GL_TEXTURE6,
	GL_TEXTURE7,
	GL_TEXTURE8,
	GL_TEXTURE9,
	GL_TEXTURE10,
	GL_TEXTURE11,
	GL_TEXTURE12,
	GL_TEXTURE13,
	GL_TEXTURE14,
	GL_TEXTURE15,
	GL_TEXTURE16,
	GL_TEXTURE17,
	GL_TEXTURE18,
	GL_TEXTURE19,
	GL_TEXTURE20,
	GL_TEXTURE21,
	GL_TEXTURE22,
	GL_TEXTURE23,
	GL_TEXTURE24,
	GL_TEXTURE25,
	GL_TEXTURE26,
	GL_TEXTURE27,
	GL_TEXTURE28,
	GL_TEXTURE29,
	GL_TEXTURE30,
	GL_TEXTURE31
};

void FOpenGL::BindTexture(GLuint textureSlot, GLuint texture)
{
	glActiveTexture(GLTextureBindingName[textureSlot]);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void FOpenGL::TextureToBufferf(int textureId, int x, int y, int width, int height, float* buffer)
{
	// 创建FBO
	GLuint fbo[1];
	glGenFramebuffers(1, fbo);
	// 绑定
	glBindFramebuffer(GL_FRAMEBUFFER, fbo[0]);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureId, 0);
	// 读取数据
	glReadPixels(x, y, width, height, GL_RGBA, GL_FLOAT, buffer);  // 这里的format和type需要和纹理一致
	// 解绑和释放
	glBindFramebuffer(GL_FRAMEBUFFER, 0);  // unbind
	glDeleteFramebuffers(1, fbo);
}