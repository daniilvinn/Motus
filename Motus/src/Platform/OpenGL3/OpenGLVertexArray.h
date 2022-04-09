#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/VertexArray.h>

namespace Motus {

	class MOTUS_API OpenGLVertexArray : public VertexArray {
	public:

		OpenGLVertexArray();
		~OpenGLVertexArray() override;

		void AddVertexBuffer(const Ref<VertexBuffer>& vbo) override;
		void AddIndexBuffer(const Ref<IndexBuffer>& ibo) override;

		void Bind() const override;
		void Unbind() const override;

	private:
		unsigned int m_VAOid;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IBO;
	};

}