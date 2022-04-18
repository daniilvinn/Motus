#pragma once

#include <Motus/Core/Base.h>
#include <stdint.h>

#include <glm/glm.hpp>

typedef unsigned int GLenum;

namespace Motus {

	enum ShaderDataType {
		Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	GLenum ShaderDataTypeToOpenGLMacro(ShaderDataType type);

	// Graphics API Shader base class definition. To be implemented per Graphics API in Motus/Platform
	class MOTUS_API Shader {
	public:
		virtual ~Shader() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		// Set all uniforms' name list to cache their location
		virtual void SetUniformList(std::initializer_list<std::string> list) = 0;
		virtual inline uint32_t GetID() const = 0;

		virtual void UploadMat4(const std::string& uniform, const glm::mat4& matrix) = 0;
		static Ref<Shader> Create(std::string vertexsrc, std::string fragmentsrc);


	private:
		virtual int32_t GetCachedUniformLocation(std::string uniform) const = 0;
	};

}