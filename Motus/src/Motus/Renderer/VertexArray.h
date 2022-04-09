#pragma once

#include <Motus/Core/Base.h>
#include <motus_pch.h>

#include "Renderer.h"

namespace Motus {

	class MOTUS_API VertexArray {
	public:
		virtual ~VertexArray() {};
		static Ref<VertexArray> Create();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vbo) = 0;
		virtual void AddIndexBuffer(const Ref<IndexBuffer>& ibo) = 0;

	};

}