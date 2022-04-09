#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/Buffers.h>
#include <Motus/Renderer/BufferLayout.h>
#include <Motus/Renderer/Shader.h>

namespace Motus {

	enum class RendererAPI {
		None = 0,		// Not supported
		OpenGL = 1,		// Supported
		D3D11 = 2,		// Not supported
		Vulkan = 3,		// Not supported
		Metal = 4		// Not supported
	};

	// Main renderer class definition. Can't be inherited.
	class MOTUS_API Renderer {
	public:
		Renderer();
		~Renderer();

		inline static RendererAPI GetAPI() { return s_API; };

	public:

	private:
		static RendererAPI s_API;
	};

}