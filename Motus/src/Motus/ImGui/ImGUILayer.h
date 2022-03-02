#pragma once

#include <Motus/Core.h>
#include <Motus/Layer.h>

namespace Motus {

	class MOTUS_API ImGUILayer : public Layer
	{
	public:

		ImGUILayer();
		~ImGUILayer();

		void OnEvent(Event& event) override;
		void OnUpdate() override;
		void OnAttach() override;
		void OnDetach() override;

	private:
		float m_Time = 0.0f;
	};


}