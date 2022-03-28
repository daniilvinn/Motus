#include <motus_pch.h>

#include "RenderLayer.h"
#include "Shader.h"

#include <glad/glad.h>
#include <Platform/OpenGL3/OpenGLShader.h>

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

		glGenBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &m_IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::pair<std::string, std::string> shaderSource = Utils::ParseGlslFile("assets/shaders/shader.glsl");

		m_Shader = new OpenGLShader(shaderSource.first, shaderSource.second);
	}

	void RenderLayer::OnDetach()
	{

	}

	void RenderLayer::OnUpdate()
	{
		m_Shader->Bind();
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