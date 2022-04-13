#include <motus_pch.h>
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Motus {

	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vao)
	{
		glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OpenGLRendererAPI::ClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

}