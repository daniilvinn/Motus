#include <motus_pch.h>
#include "OpenGLVertexArray.h"

#include <Motus/Renderer/Shader.h>

#include <glad/glad.h>

namespace Motus {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_VAOid);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_VAOid);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vbo)
	{
		MT_CORE_ASSERT(!(vbo->GetLayout().GetElements().empty()), "Vertex Buffer has no layout!");
		glBindVertexArray(m_VAOid);
		vbo->Bind();
		
		const auto& layout = vbo->GetLayout();

		// === Setting up attributes ===
		uint8_t i = 0;
		for (const auto& element : layout.GetElements()) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLMacro(element.type),
				element.normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.offset
			);
			i++;
		}
		// =============================

		m_VertexBuffers.push_back(vbo);
	}

	void OpenGLVertexArray::AddIndexBuffer(const Ref<IndexBuffer>& ibo)
	{
		glBindVertexArray(m_VAOid);
		ibo->Bind();
		m_IBO = ibo;
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_VAOid);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(NULL);
	}

}