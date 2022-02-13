#pragma once

#include "Core.h"
#include "Logger.h"

namespace Motus {
	class MOTUS_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		
	};

	Application* CreateApplication();
}
