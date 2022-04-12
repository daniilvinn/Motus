#pragma once

#include <Motus/Core/Base.h>

#include "Buffers.h"

namespace Motus {

	class MOTUS_API VertexArray {
	public:
		virtual ~VertexArray() {};
		static Ref<VertexArray> Create();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vbo) = 0;
		virtual void AddIndexBuffer(const Ref<IndexBuffer>& ibo) = 0;

		inline virtual Ref<IndexBuffer> GetIndexBuffer() = 0;

	};

}