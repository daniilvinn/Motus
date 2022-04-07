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

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		m_VBO = VertexBuffer::Create(vertices, sizeof(vertices));
		m_VBO->SetLayout(BufferLayout{
			{Float3, "a_Position"}
		});

		uint8_t i = 0;
		for (auto element : m_VBO->GetLayout()) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i, 
				element.GetComponentCount(), 
				ShaderDataTypeToOpenGLMacro(element.type), 
				element.normalized ? GL_TRUE : GL_FALSE, 
				m_VBO->GetLayout().GetStride(), 
				(const void*)element.offset
			);
			i++;
		}

		m_IBO = IndexBuffer::Create(indices, sizeof(indices));

		ShaderSource shaderSource = Utils::ParseGlslFile("assets/shaders/shader.glsl");
		m_Shader = CreateRef<OpenGLShader>(shaderSource.first, shaderSource.second);
	}

	void RenderLayer::OnDetach()
	{

	}

	void RenderLayer::OnUpdate()
	{
		m_Shader->Bind();
		m_IBO->Bind();
		glBindVertexArray(m_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void RenderLayer::OnImGuiRender()
	{

	}

	void RenderLayer::OnEvent(Event& event)
	{
	}

}