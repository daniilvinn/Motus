#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/VertexArray.h>
#include <Motus/Renderer/BufferLayout.h>

namespace Motus {

	class MOTUS_API OpenGLVertexArray : public VertexArray {
	public:

		OpenGLVertexArray();
		~OpenGLVertexArray() override;

		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const Ref<VertexBuffer>& vbo) override;
		void AddIndexBuffer(const Ref<IndexBuffer>& ibo) override;

		Ref<IndexBuffer> GetIndexBuffer() override { return m_IBO; };

	private:
		unsigned int m_VAOid;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IBO;
	};

}