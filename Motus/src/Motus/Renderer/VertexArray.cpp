#include <motus_pch.h>
#include "VertexArray.h"

#include <Platform/OpenGL3/OpenGLVertexArray.h>

namespace Motus {



	Ref<Motus::VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MT_ASSERT(false, "None is currently not supported!");
			break;

		case RendererAPI::OpenGL:
			return CreateRef<OpenGLVertexArray>();
			break;

		case RendererAPI::D3D11:
			MT_ASSERT(false, "D3D11 is currently not supported!");
			break;

		case RendererAPI::Vulkan:
			MT_ASSERT(false, "Vulkan is currently not supported!");
			break;

		case RendererAPI::Metal:
			MT_ASSERT(false, "Metal is currently not supported!");
			break;

		default:
			break;
		}
	}

}