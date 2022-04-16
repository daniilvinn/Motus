#pragma once

#include <Motus/Core/Base.h>

#include <Motus/Renderer/VertexArray.h>

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
		virtual void DrawIndexed(const Ref<VertexArray>& vao) = 0;
		virtual void Clear() = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;
		virtual void SetViewport(int x, int y, int width, int height) = 0;

	private:
		static API s_API;
	};

}