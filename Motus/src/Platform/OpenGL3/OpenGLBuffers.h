#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/Buffers.h>
#include <glad/glad.h>

namespace Motus {

	class OpenGLVertexBuffer final : public VertexBuffer {
	public:
		OpenGLVertexBuffer();
		OpenGLVertexBuffer(float* data, uint32_t size);
		~OpenGLVertexBuffer() override;

		void Bind() const override;
		void Unbind() const override;

		void SetLayout(const BufferLayout& layout) override;
		inline BufferLayout GetLayout() const override { return m_Layout; };

		void UploadData(float* data, uint32_t size) override;

	private:
		GLuint m_VBOid;
		BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer final : public IndexBuffer {
	public:
		OpenGLIndexBuffer();
		OpenGLIndexBuffer(unsigned int* data, uint32_t size);
		~OpenGLIndexBuffer() override;

		void Bind() const override;
		void Unbind() const override;

		inline uint32_t GetCount() const override { return m_Count; };

		void UploadData(unsigned int* data, uint32_t size) override;

	private:
		GLuint m_IBOid;
		uint32_t m_Count;
	};

}