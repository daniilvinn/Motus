#include <motus_pch.h>
#include <Motus/Core/Base.h>

#include "Motus/Renderer/Shader.h"
#include <stdint.h>

namespace Motus {

	class MOTUS_API OpenGLShader final : public Shader {
	public:
		OpenGLShader(const std::string& vertsrc, const std::string& fragsrc);
		~OpenGLShader();

		void Bind() const override;
		void Unbind() const override;

		void SetUniformList(std::initializer_list<std::string> list) override;

		void UploadMat4(const std::string& uniform, const glm::mat4& matrix) override;

		inline uint32_t GetID() const override { return m_ShaderID; };
	private:
		inline int32_t GetCachedUniformLocation(std::string uniform) const override { return m_UniformLocationCache.find(uniform)->second; };

	private:
		uint32_t m_ShaderID;
		std::unordered_map<std::string, int32_t> m_UniformLocationCache;
	};

}