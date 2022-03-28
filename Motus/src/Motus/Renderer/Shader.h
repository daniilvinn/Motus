#pragma once

#include <Motus/Core/Base.h>
#include <stdint.h>

// TODO: Parse .glsl files.
// (?) Implement ParseToShaderSource() function in Utils namespace
// (?) Create Utils namespace

namespace Motus {

	// Graphics API Shader base class definition. To be implemented per Graphics API in Motus/Platform
	class MOTUS_API Shader {
	public:
		~Shader();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual inline uint32_t GetID() const = 0;
	};

}