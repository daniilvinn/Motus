#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Core/Layer.h>
#include <Motus/Renderer/Shader.h>

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
		uint32_t m_VBO;
		uint32_t m_VAO;
		uint32_t m_IBO;
		Shader* m_Shader;
	};

}