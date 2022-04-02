#include <motus_pch.h>

#include <Platform/OpenGL3/OpenGLBuffers.h>
#include "Buffers.h"
#include "Renderer.h"

namespace Motus {



	Ref<VertexBuffer> VertexBuffer::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MT_CORE_ASSERT(false, "None is currently not supperted!");
			break;
		case RendererAPI::OpenGL:
			return std::make_unique<OpenGLVertexBuffer>();
			break;
		case RendererAPI::D3D11:
			MT_CORE_ASSERT(false, "DirectX11 is currently not supperted!");
			break;
		case RendererAPI::Vulkan:
			MT_CORE_ASSERT(false, "Vulkan is currently not supperted!");
			break;
		case RendererAPI::Metal:
			MT_CORE_ASSERT(false, "Metal is currently not supperted!");
			break;

		default:
			MT_CORE_ASSERT(false, "");
		}
	}

	Ref<IndexBuffer> IndexBuffer::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MT_CORE_ASSERT(false, "None is currently not supported!");
			break;
		case RendererAPI::OpenGL:
			return std::make_unique<OpenGLIndexBuffer>();
			break;
		case RendererAPI::D3D11:
			MT_CORE_ASSERT(false, "DirectX11 is currently not supported!");
			break;
		case RendererAPI::Vulkan:
			MT_CORE_ASSERT(false, "Vulkan is currently not supported!");
			break;
		case RendererAPI::Metal:
			MT_CORE_ASSERT(false, "Metal is currently not supported!");
			break;

		default:
			MT_CORE_ASSERT(false, "");
		}
	}

}