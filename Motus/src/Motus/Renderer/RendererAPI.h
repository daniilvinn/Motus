#pragma once

#include <Motus/Core/Base.h>

namespace Motus {

	class MOTUS_API RendererAPI {
	public:
		enum class API {
			None = 0,		// Not supported
			OpenGL = 1,		// Supported
			D3D11 = 2,		// Not supported
			Vulkan = 3,		// Not supported
			Metal = 4		// Not supported
		};

		inline static API GetAPI() { return s_API; };

	private:
		static API s_API;
	};

}