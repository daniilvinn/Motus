#include <motus_pch.h>

#include "Buffers.h"
#include "Renderer.h"

#include <Platform/OpenGL3/OpenGLBuffers.h>

namespace Motus {



	Ref<VertexBuffer> VertexBuffer::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MT_CORE_ASSERT(false, "None is currently not supperted!");
			break;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLVertexBuffer>();
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


	Ref<VertexBuffer> VertexBuffer::Create(float* data, uint16_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MT_CORE_ASSERT(false, "None is currently not supperted!");
			break;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(data, size);
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
			return CreateRef<OpenGLIndexBuffer>();
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

	Ref<IndexBuffer> IndexBuffer::Create(unsigned int* data, uint16_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			MT_CORE_ASSERT(false, "None is currently not supported!");
			break;
		case RendererAPI::OpenGL:
			return CreateRef<OpenGLIndexBuffer>(data, size);
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