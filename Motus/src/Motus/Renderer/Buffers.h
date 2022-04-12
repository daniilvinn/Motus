#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/BufferLayout.h>

namespace Motus {

	class VertexBuffer {
	public:
		virtual ~VertexBuffer() {};

		static Ref<VertexBuffer> Create();
		static Ref<VertexBuffer> Create(float* data, uint32_t size);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual inline BufferLayout GetLayout() const = 0;

		virtual void UploadData(float* data, uint32_t size) = 0;

	public:

	};

	class IndexBuffer {
	public:

		virtual ~IndexBuffer() {};

		static Ref<IndexBuffer> Create();
		static Ref<IndexBuffer> Create(unsigned int* data, uint32_t size);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		virtual void UploadData(unsigned int* data, uint32_t size) = 0;
	};
}