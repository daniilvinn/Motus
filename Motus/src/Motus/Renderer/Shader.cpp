#include <motus_pch.h>
#include "Shader.h"
#include "Renderer.h"

#include <glad/glad.h>
#include <Platform/OpenGL3/OpenGLShader.h>

namespace Motus {

	GLenum ShaderDataTypeToOpenGLMacro(ShaderDataType type) {
		switch (type)
		{
		case Motus::Float:		return GL_FLOAT;
		case Motus::Float2:		return GL_FLOAT;
		case Motus::Float3:		return GL_FLOAT;
		case Motus::Float4:		return GL_FLOAT;
		case Motus::Mat3:		return GL_FLOAT;
		case Motus::Mat4:		return GL_FLOAT;
		case Motus::Int:		return GL_INT;
		case Motus::Int2:		return GL_INT;
		case Motus::Int3:		return GL_INT;
		case Motus::Int4:		return GL_INT;
		case Motus::Bool:		return GL_BOOL;
		default:
			MT_CORE_ASSERT(false, "Invalid shader data type!");
		}
	}

	Ref<Shader> Shader::Create(std::string vertexsrc, std::string fragmentsrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			MT_ASSERT(false, "None is currently not supported!");
			break;

		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLShader>(vertexsrc, fragmentsrc);
			break;

		case RendererAPI::API::D3D11:
			MT_ASSERT(false, "D3D11 is currently not supported!");
			break;

		case RendererAPI::API::Vulkan:
			MT_ASSERT(false, "Vulkan is currently not supported!");
			break;

		case RendererAPI::API::Metal:
			MT_ASSERT(false, "Metal is currently not supported!");
			break;

		default:
			break;
		}
	}

}