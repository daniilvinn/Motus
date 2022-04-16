#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/RendererAPI.h>

namespace Motus {

	class MOTUS_API RenderCommand {
	public:
		static inline void Clear() { s_API->Clear(); };
		static inline void ClearColor(float r, float g, float b, float a) { s_API->ClearColor(r, g, b, a); };
		static inline void DrawIndexed(const Ref<VertexArray>& vao) { s_API->DrawIndexed(vao); };
		static inline void SetViewport(int x, int y, int width, int height) { s_API->SetViewport(x, y, width, height); };

	private:
		static RendererAPI* s_API;
	};

}