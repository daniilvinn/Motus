#include <motus_pch.h>
#include "Renderer.h"

#include <Motus/Renderer/RenderCommand.h>

#include <Platform/OpenGL3/OpenGLRendererAPI.h>

// Renderer methods implementation
namespace Motus {

	// REMINDER: Change RendererAPI pointer if want to change using rendering API (OpenGL, D3D etc.)
	RendererAPI* Renderer::s_API = new OpenGLRendererAPI;
	Renderer::SceneData Renderer::m_SceneData = SceneData();

	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::BeginScene(const OrthographicCamera& camera)
	{
		m_SceneData.m_VPMatrix = camera.GetVPMatrix();
	}

	void Renderer::EndScene()
	{

	}

	// TODO: implement deferred renderer
	void Renderer::Submit(const Ref<VertexArray>& vao)
	{
		vao->Bind();
		RenderCommand::DrawIndexed(vao);
	}

}