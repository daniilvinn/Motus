#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/Context.h>

#include <GLFW/glfw3.h>

namespace Motus {
	

	// Implementation of OpenGLContext class, which inherits from
	// GraphicsAPIContext base class. Represents controls of
	// OpenGL initialization and swap chain.
	class MOTUS_API OpenGLContext final : public GraphicsAPIContext
	{
	public:
		OpenGLContext(GLFWwindow* handle);
		~OpenGLContext() {}

		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_Handle;
	};

}