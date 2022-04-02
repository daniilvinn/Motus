#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/Renderer.h>
#include <motus_pch.h>

namespace Motus {

	class VertexBuffer {
	public:
		virtual ~VertexBuffer() {};

		static Ref<VertexBuffer> Create();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void UploadData(float* data) = 0;

	public:

	};

	class IndexBuffer {
	public:

		virtual ~IndexBuffer() {};

		static Ref<IndexBuffer> Create();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void UploadData(unsigned int* data) = 0;
	};
}