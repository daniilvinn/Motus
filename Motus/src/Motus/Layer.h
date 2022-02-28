#pragma once

#include "Motus/Core.h"
#include "Motus/Events/Event.h"

namespace Motus {
	// Motus rendering layer base class declaration 
	class MOTUS_API Layer {
	public:
		// Constructor / Destructor
		Layer(std::string id = "Layer");
		virtual ~Layer();

		// Methods
		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		// Getters
		inline const std::string& GetID() const { return m_DebugID; };

	private:
		std::string m_DebugID;
	};
}