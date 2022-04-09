#pragma once

#include <Motus/Core/Base.h>
#include <motus_pch.h>
#include <glad/glad.h>

namespace Motus {
	
	enum ShaderDataType {
		Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	constexpr static uint8_t GetSizeOfType(ShaderDataType datatype) {
		switch (datatype)
		{
		case Motus::ShaderDataType::Float:		return 4 * 1;
		case Motus::ShaderDataType::Float2:		return 4 * 2;
		case Motus::ShaderDataType::Float3:		return 4 * 3;
		case Motus::ShaderDataType::Float4:		return 4 * 4;
		case Motus::ShaderDataType::Mat3:		return 4 * 3 * 3;
		case Motus::ShaderDataType::Mat4:		return 4 * 4 * 4;
		case Motus::ShaderDataType::Int:		return 4 * 1;
		case Motus::ShaderDataType::Int2:		return 4 * 2;
		case Motus::ShaderDataType::Int3:		return 4 * 3;
		case Motus::ShaderDataType::Int4:		return 4 * 4;
		case Motus::ShaderDataType::Bool:		return 1;
		default:
			MT_CORE_ASSERT(false, "Invalid shader data type!");
		}
	}

	constexpr GLenum ShaderDataTypeToOpenGLMacro(ShaderDataType type) {
		switch (type)
		{
		case Motus::Float:		return GL_FLOAT;
		case Motus::Float2:		return GL_FLOAT;
		case Motus::Float3:		return GL_FLOAT;
		case Motus::Float4:		return GL_FLOAT;
		case Motus::Mat3:		return GL_FLOAT;
		case Motus::Mat4:		return GL_FLOAT;
		case Motus::Int:		return GL_INT;
		case Motus::Int2:		return GL_INT;
		case Motus::Int3:		return GL_INT;
		case Motus::Int4:		return GL_INT;
		case Motus::Bool:		return GL_BOOL;
		default:
			MT_CORE_ASSERT(false, "Invalid shader data type!");
		}
	}

	struct BufferLayoutElement {
		std::string name;
		uint8_t size;
		uint8_t offset;
		ShaderDataType type;
		bool normalized;

		BufferLayoutElement(ShaderDataType datatype, std::string id)
			: type(datatype), name(id), normalized(true)
		{
			size = GetSizeOfType(datatype);
		}

		uint8_t GetComponentCount() const {
			switch (type)
			{
			case Motus::Float:		return 1;
			case Motus::Float2:		return 2;
			case Motus::Float3:		return 3;
			case Motus::Float4:		return 4;
			case Motus::Mat3:		return 3 * 3;
			case Motus::Mat4:		return 4 * 4;
			case Motus::Int:		return 1;
			case Motus::Int2:		return 2;
			case Motus::Int3:		return 3;
			case Motus::Int4:		return 4;
			case Motus::Bool:		return 1;
			default:
				MT_CORE_ASSERT(false, "Invalid shader data type!");
				break;
			}
		}
	};

	class MOTUS_API BufferLayout {
	public:
		BufferLayout() {}

		BufferLayout(const std::initializer_list<BufferLayoutElement>& elements) 
			: m_Layout(elements)
		{
			ComputeLayout(); 
		}

		~BufferLayout() {};

		// Elements vector
		inline uint8_t GetStride() const { return m_Stride; }
		inline const std::vector<BufferLayoutElement>& GetElements() const { return m_Layout; }

		// Iterator definition to be able to use range-based loop.
		std::vector<BufferLayoutElement>::iterator begin() { return m_Layout.begin(); }
		std::vector<BufferLayoutElement>::iterator end() { return m_Layout.end(); }
	private:
		void ComputeLayout() {
			uint8_t offset = 0;
			for (auto& element : m_Layout) {
				element.offset = offset;
				offset += element.size;
				m_Stride += element.size;
			}
		};

	private:
		// The layout itself. Represented by a vector of Layout Elements, which are basically attributes.
		std::vector<BufferLayoutElement> m_Layout;
		uint8_t m_Stride = 0;
	};

}