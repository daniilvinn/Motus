#pragma once

#include <Motus/Core/Base.h>

namespace Motus {

	// Declaration of GraphicsAPIContext base class
	// Represents interface to control Graphics API initialization and
	// control swap chain
	class MOTUS_API GraphicsAPIContext {
	public:

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

	private:

	};

}