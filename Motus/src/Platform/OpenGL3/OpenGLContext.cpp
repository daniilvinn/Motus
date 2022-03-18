#include <motus_pch.h>

#include "OpenGLContext.h"

#include <glad/glad.h>

namespace Motus {
	OpenGLContext::OpenGLContext(GLFWwindow* handle)
		: m_Handle(handle)
	{ MT_CORE_ASSERT(handle, "Window handle pointer is null!") }

	void OpenGLContext::Init()
	{
		int gladInitValidator = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MT_CORE_ASSERT(gladInitValidator, "Failed to load GLAD!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Handle);
	}
}