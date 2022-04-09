#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Core/Layer.h>
#include <Motus/Renderer/Shader.h>
#include <Motus/Renderer/Buffers.h>
#include <Motus/Renderer/VertexArray.h>

#include <stdint.h>

namespace Motus {

	// Main layer definition. Renders all objects in scene
	class MOTUS_API RenderLayer final : public Layer {
	public:
		RenderLayer();
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnImGuiRender() override;
		void OnEvent(Event& event) override;
	private:
		using ShaderSource = std::pair<std::string, std::string>;

		Ref<VertexBuffer> m_VBO;
		Ref<IndexBuffer> m_IBO;
		Ref<VertexArray> m_VAO;
		Ref<Shader> m_Shader;
	};

}