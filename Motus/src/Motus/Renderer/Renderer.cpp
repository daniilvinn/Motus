#include <motus_pch.h>
#include "Renderer.h"

#include <Platform/OpenGL3/OpenGLRendererAPI.h>

// Renderer methods implementation
namespace Motus {

	// REMINDER: Change RendererAPI pointer if want to change using rendering API (OpenGL, D3D etc.)
	RendererAPI* Renderer::s_API = new OpenGLRendererAPI;

	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::BeginScene()
	{

	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const Ref<VertexArray>&)
	{
		
	}
	


}