#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/RendererAPI.h>

namespace Motus {

	class MOTUS_API OpenGLRendererAPI : public RendererAPI {
	public:
		void DrawIndexed(const Ref<VertexArray>& vao) override;
		void Clear() override;
		void ClearColor(float r, float g, float b, float a) override;
		virtual void SetViewport(int x, int y, int width, int height) override;
	private:
		
	};

}