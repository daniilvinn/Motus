#pragma once

#include <Motus/Core/Base.h>
#include <Motus/Renderer/VertexArray.h>
#include <Motus/Renderer/Shader.h>
#include <Motus/Renderer/RendererAPI.h>

#include <Motus/Renderer/OrthoCamera.h>

#include <glm/glm.hpp>

namespace Motus {

	// Main renderer class definition. Can't be inherited.
	class MOTUS_API Renderer final {
	public:
		struct SceneData {
			glm::mat4 m_VPMatrix;
		};

	public:

		Renderer();
		~Renderer();

		// TODO: Implement sorting and culling 
		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<VertexArray>& vao);

		inline static RendererAPI::API GetAPI() { return s_API->GetAPI(); };

		inline static const SceneData& GetSceneData() { return m_SceneData; }

	private:
		static RendererAPI* s_API;
		static SceneData m_SceneData;

	};

}