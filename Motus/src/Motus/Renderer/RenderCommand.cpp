#include <motus_pch.h>
#include "RenderCommand.h"

#include <Platform/OpenGL3/OpenGLRendererAPI.h>

namespace Motus {

	RendererAPI* RenderCommand::s_API = new OpenGLRendererAPI;

}