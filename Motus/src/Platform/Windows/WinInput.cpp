#include <motus_pch.h>
#include "WinInput.h"

#include <GLFW/glfw3.h>
#include <Motus/Core/Application.h>

namespace Motus {

	bool WinInput::IsKeyPressedImpl(int keycode) const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNative());
		int status = glfwGetKey(window, keycode);
		return status == GLFW_PRESS || status == GLFW_REPEAT;
	}

	bool WinInput::IsMouseButtonPressedImpl(int button) const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNative());
		int status = glfwGetMouseButton(window, button);
		return status == GLFW_PRESS;
	}

	std::pair<float, float> WinInput::GetMousePosImpl() const
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNative());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return { x, y };
	}
	


	float WinInput::GetMousePosXImpl() const
	{
		return GetMousePosImpl().first;
	}

	float WinInput::GetMousePosYImpl() const
	{
		return GetMousePosImpl().second;
	}

}