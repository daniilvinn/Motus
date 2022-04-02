#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/Buffers.h>
#include <glad/glad.h>

namespace Motus {

	class OpenGLVertexBuffer final : public VertexBuffer {
	public:
		OpenGLVertexBuffer();
		~OpenGLVertexBuffer() override;

		void Bind() const override;
		void Unbind() const override;
		void UploadData(float* data) override;

	private:
		GLuint m_VBOid;

	};

	class OpenGLIndexBuffer final : public IndexBuffer {
	public:
		OpenGLIndexBuffer();
		~OpenGLIndexBuffer() override;

		void Bind() const override;
		void Unbind() const override;
		void UploadData(unsigned int* data) override;

	private:
		GLuint m_IBOid;

	};

}