#include <motus_pch.h>
#include "VertexArray.h"

#include <Motus/Renderer/Renderer.h>

#include <Platform/OpenGL3/OpenGLVertexArray.h>

namespace Motus {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			MT_ASSERT(false, "None is currently not supported!");
			break;

		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexArray>();
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