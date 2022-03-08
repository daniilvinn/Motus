#pragma once

#include "Motus/Core/Base.h"
#include "Motus/Core/Layer.h"

#include <vector>

namespace Motus {
	
	// Motus Layer Stack implementation class
	// Represents basically a wrapper to std::vector<Layer*>
	
	// TODO layer stack
	class MOTUS_API LayerStack
	{
	public:
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }
		std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }

	private:
		std::vector<Layer*> m_LayerStack;
		unsigned int m_InsertIndex = 0;
	};
}