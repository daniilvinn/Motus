#include <motus_pch.h>
#include "OpenGLBuffers.h"

namespace Motus {

	// OpenGL Vertex Buffer Object class
	OpenGLVertexBuffer::OpenGLVertexBuffer()
	{
		glCreateBuffers(1, &m_VBOid);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, uint16_t size)
	{
		glCreateBuffers(1, &m_VBOid);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOid);
		glBufferData(GL_ARRAY_BUFFER, size, (const void*)data, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_VBOid);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOid);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}

	void OpenGLVertexBuffer::UploadData(float* data, uint16_t size)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOid);
		glBufferData(GL_ARRAY_BUFFER, size, (const void*)data, GL_STATIC_DRAW);
	}

	void OpenGLVertexBuffer::SetLayout(const BufferLayout& layout)
	{
		m_Layout = layout;
	}

	// OpenGL Index Buffer Object class
	OpenGLIndexBuffer::OpenGLIndexBuffer()
	{
		glCreateBuffers(1, &m_IBOid);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, uint16_t size)
	{
		glCreateBuffers(1, &m_IBOid);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOid);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, (const void*)data, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_IBOid);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOid);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	}

	// TODO: upload 16-bit index values
	void OpenGLIndexBuffer::UploadData(unsigned int* data, uint16_t size)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOid);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, (const void*)data, GL_STATIC_DRAW);
	}

}