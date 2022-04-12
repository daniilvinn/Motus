#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/VertexArray.h>
#include <Motus/Renderer/Shader.h>
#include <Motus/Renderer/RendererAPI.h>

namespace Motus {

	// Main renderer class definition. Can't be inherited.
	class MOTUS_API Renderer final {
	public:
		Renderer();
		~Renderer();

		// TODO: Implement sorting and culling 
		static void BeginScene();
		static void EndScene();

		static void Submit(const Ref<VertexArray>& vao);

		inline static RendererAPI::API GetAPI() { return s_API->GetAPI(); };

	public:

	private:
		static RendererAPI* s_API;
	};

}