#include <motus_pch.h>

#include "Utils.h"
#include <fstream>

namespace Motus {

	namespace Utils {

		std::pair<std::string, std::string> ParseGlslFile(const std::string& filepath)
		{
			// PARSE PREPARATION STAGE
			std::ifstream stream(filepath);

			enum class ShaderType {
				NONE = -1,
				VERTEX = 0,
				FRAGMENT = 1
			};

			ShaderType type = ShaderType::NONE;

			// PARSE STAGE
			std::string line;
			std::stringstream ss[2];
			while (getline(stream, line)) {
				if (line.find("#shadertype") != std::string::npos) {
					if (line.find("vertex") != std::string::npos) {
						type = ShaderType::VERTEX;
					}
					else if (line.find("fragment") != std::string::npos) {
						type = ShaderType::FRAGMENT;
					}
				}
				else {
					ss[(int)type] << line << '\n';
				}
			}
			
			// RETURN
			return {
				ss[0].str(),
				ss[1].str()
			};
		}
	}
}