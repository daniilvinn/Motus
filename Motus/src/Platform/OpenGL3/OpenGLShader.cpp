#include <motus_pch.h>
#include "OpenGLShader.h"

#include <glad/glad.h>

namespace Motus {

	OpenGLShader::OpenGLShader(const std::string& vertsrc, const std::string& fragsrc)
	{
		std::string vertexSource = vertsrc;
		std::string fragmentSource = fragsrc;

		// VERTEX SHADER COMPILATION STAGE
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* source = (const GLchar*)vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		glCompileShader(vertexShader);

		// Vertex shader validation
		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(vertexShader);

			MT_CORE_ERROR("Failed to compile vertex shader! Info Log: {0}", &infoLog[0]);

			return;
		}

		// FRAGMENT SHADER COMPILATION STAGE
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		source = (const GLchar*)fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		glCompileShader(fragmentShader);

		// Fragment shader validation
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);

			MT_CORE_ERROR("Failed to compile fragment shader! Info Log: {0}", &infoLog[0]);

			return;
		}

		// LINKING SHADERS INTO A PROGRAM STAGE
		m_ShaderID = glCreateProgram();
		
		glAttachShader(m_ShaderID, vertexShader);
		glAttachShader(m_ShaderID, fragmentShader);

		glLinkProgram(m_ShaderID);

		// Shader program validation
		GLint isLinked = 0;
		glGetProgramiv(m_ShaderID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_ShaderID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_ShaderID, maxLength, &maxLength, &infoLog[0]);

			// Deletion
			glDeleteProgram(m_ShaderID);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			MT_CORE_ERROR("Failed to link a shader program! Info Log: {0}", &infoLog[0]);

			return;
		}

		glDetachShader(m_ShaderID, vertexShader);
		glDetachShader(m_ShaderID, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_ShaderID);
		MT_CORE_INFO("Shader with ID {0} was deleted", m_ShaderID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_ShaderID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(NULL);
	}


}