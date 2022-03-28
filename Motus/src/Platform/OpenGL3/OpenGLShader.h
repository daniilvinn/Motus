#include <motus_pch.h>
#include "Motus/Renderer/Shader.h"
#include <stdint.h>

namespace Motus {

	class OpenGLShader final : Shader {
	public:
		OpenGLShader(const std::string& vertsrc, const std::string& fragsrc);
		~OpenGLShader();

		void Bind() const override;
		void Unbind() const override;

		inline uint32_t GetID() const override { return m_ShaderID; };
	private:
		uint32_t m_ShaderID;
	};

}