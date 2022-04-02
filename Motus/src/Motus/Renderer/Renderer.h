#pragma once

#include <Motus/Core/Base.h>

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

		// Type aliases
		template <typename T>
		using Ref = std::unique_ptr<T>;

		template <typename T>
		using Scope = std::shared_ptr<T>;

	private:
		static RendererAPI s_API;
	};

}