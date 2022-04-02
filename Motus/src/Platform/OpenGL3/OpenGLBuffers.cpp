#include <motus_pch.h>
#include "OpenGLBuffers.h"

namespace Motus {

	// OpenGL Vertex Buffer Object class
	OpenGLVertexBuffer::OpenGLVertexBuffer()
	{
		glCreateBuffers(1, &m_VBOid);
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

	void OpenGLVertexBuffer::UploadData(float* data)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOid);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), (const void*)data, GL_STATIC_DRAW);
		
	}

	// OpenGL Index Buffer Object class
	OpenGLIndexBuffer::OpenGLIndexBuffer()
	{
		glCreateBuffers(1, &m_IBOid);
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
	void OpenGLIndexBuffer::UploadData(unsigned int* data)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOid);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), (const void*)data, GL_STATIC_DRAW);
	}

}