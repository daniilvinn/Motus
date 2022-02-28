#include "motus_pch.h"
#include "LayerStack.h"


namespace Motus {
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_LayerStack)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerStack.emplace(m_LayerStack.begin() + m_InsertIndex, layer);
		m_InsertIndex++;
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto i = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
		if (i != m_LayerStack.end()) {
			// Maybe next line should be deleted :/
			MT_CORE_ASSERT(false, "Deleted not existing layer");
			m_LayerStack.erase(i);
			m_InsertIndex--;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_LayerStack.emplace_back(overlay);
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto i = std::find(m_LayerStack.begin(), m_LayerStack.end(), overlay);
		if (i != m_LayerStack.end()) {
			// Maybe next line should be deleted :/
			MT_CORE_ASSERT(false, "Deleted not existing overlay");
			m_LayerStack.erase(i);
		}
	}
}