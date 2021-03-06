#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Core/Layer.h>

#include <Motus/Events/MouseEvent.h>
#include <Motus/Events/KeyEvent.h>
#include <Motus/Events/ApplicationEvent.h>

namespace Motus {

	class MOTUS_API ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;
		void OnImGuiRender() override;
		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& event) override;

		void ImGuiBegin();
		void ImGuiEnd();

	private:
		float m_Time = 0.0f;
	};


}