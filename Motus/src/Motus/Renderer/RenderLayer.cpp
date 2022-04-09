#include <motus_pch.h>

#include "RenderLayer.h"
#include "Renderer.h"

#include <glad/glad.h>
#include <Platform/OpenGL3/OpenGLShader.h>
#include <Platform/OpenGL3/OpenGLBuffers.h>

#include <Motus/Utils/Utils.h>

namespace Motus {

	RenderLayer::RenderLayer()
	: Layer("RenderLayer") {}

	void RenderLayer::OnAttach()
	{
		// setting quad vertex buffer data
		float vertices[] = {
			// Position				// Color
			-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		{
			// Create Vertex Buffer and set layout
			m_VBO = VertexBuffer::Create(vertices, sizeof(vertices));
			m_VBO->SetLayout({
				{ Float3, "a_Position" },
				{ Float3, "a_Color;"}
			});
		}

		{
			// Create Index Buffer
			m_IBO = IndexBuffer::Create(indices, sizeof(indices));
		}

		{
			// Create Vertex Array and set buffers
			m_VAO = VertexArray::Create();
			m_VAO->AddVertexBuffer(m_VBO);
			m_VAO->AddIndexBuffer(m_IBO);
		}

		{
			// Creating Shader Program
			ShaderSource shaderSource = Utils::ParseGlslFile("assets/shaders/shader.glsl");
			m_Shader = CreateRef<OpenGLShader>(shaderSource.first, shaderSource.second);
		}

	}

	void RenderLayer::OnDetach()
	{

	}

	void RenderLayer::OnUpdate()
	{
		m_Shader->Bind();
		m_VAO->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void RenderLayer::OnImGuiRender()
	{

	}

	void RenderLayer::OnEvent(Event& event)
	{
	}

}