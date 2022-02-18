#pragma once
#include "Core.h"

namespace Motus {

	struct WindowProperties {
		std::string m_Title;
		uint16_t m_WindowWidth;
		uint16_t m_WindowHeight;

		WindowProperties(
			const std::string& title = "Motus Engine", 
			uint16_t width = 1280, 
			uint16_t height = 720
		) : m_Title(title), m_WindowWidth(width), m_WindowHeight(height) {}

	};


	// Desktop Window interface class implementation.
	class MOTUS_API Window
	{
	public:
		virtual void OnUpdate() = 0;

		virtual void SetVSync() = 0;
		virtual bool isVSync() const = 0;

		// Get Window Properties 
		virtual inline uint16_t GetWidth() const = 0;
		virtual inline uint16_t GetHeight() const = 0;
		virtual inline std::string GetTitle() const = 0;

		static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties());
	};
}