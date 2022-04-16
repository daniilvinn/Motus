#include <Motus.h>
#include <imgui/imgui.h>

using namespace Motus;

class RenderLayer : public Motus::Layer {
public:
	using ShaderSource = std::pair<std::string, std::string>;

	void OnAttach() override
	{
		float vertices[] = {
			// Position				// Color
			-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f
		};

		float greenvert[] = {
			// Position				// Color
			-1.0f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,
			 1.0f, -0.5f, 0.0f,		1.0f, 1.0f, 0.0f,
			 1.0f,  0.5f, 0.0f,		1.0f, 0.0f, 1.0f,
			-1.0f,  0.5f, 0.0f,		1.0f, 0.0f, 0.0f
		};


		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		{
			// Create Vertex Buffer and set layout
			m_VBO = Motus::VertexBuffer::Create(vertices, sizeof(vertices));
			m_VBO->SetLayout({
				{ Motus::ShaderDataType::Float3, "a_Position" },
				{ Motus::ShaderDataType::Float3, "a_Color;"}
				});
		}

		{
			// Create Index Buffer
			m_IBO = Motus::IndexBuffer::Create(indices, sizeof(indices));
		}

		{
			// Create Vertex Array and set buffers
			m_VAO = Motus::VertexArray::Create();
			m_VAO->AddVertexBuffer(m_VBO);
			m_VAO->AddIndexBuffer(m_IBO);
		}

		{
			// Creating Shader Program
			ShaderSource shaderSource = Motus::Utils::ParseGlslFile("assets/shaders/shader.glsl");
			m_Shader = Motus::Shader::Create(shaderSource.first, shaderSource.second);
		}

		{
			// Camera setup
			m_Camera.SetProjection(-1.6f, 1.6f, -0.9f, 0.9f);
			m_Camera.SetPosition(glm::vec3(0.3f, 0.3f, 0.0f));
		}
	}

	void OnDetach() override
	{
		
	}

	void OnUpdate() override
	{
		Motus::Renderer::BeginScene(m_Camera);
		{
			const Renderer::SceneData& sceneData = Renderer::GetSceneData();

			m_Shader->Bind();
			m_Shader->UploadMat4("u_VP", sceneData.m_VPMatrix);

			Motus::Renderer::Submit(m_VAO);
		}
		Motus::Renderer::EndScene();
	}

	void OnImGuiRender() override 
	{
		ImGui::Begin("Camera Controller");
		static glm::vec3 cameraposition = glm::vec3(0.0f);
		static float camerarotation;
		ImGui::SliderFloat2("Position", glm::value_ptr(cameraposition), -1.0f, 1.0f);
		ImGui::SliderFloat("Rotation", &camerarotation, 0.0f, 360.0f);
		m_Camera.SetRotation(camerarotation);
		m_Camera.SetPosition(cameraposition);
		ImGui::End();
	}

	void OnEvent(Motus::Event& event) override {}

private:
	std::shared_ptr<VertexBuffer> m_VBO;
	std::shared_ptr<IndexBuffer> m_IBO;
	std::shared_ptr<VertexArray> m_VAO;
	std::shared_ptr<Shader> m_Shader;
	OrthographicCamera m_Camera;
};

class Sandbox : public Motus::Application {
public:
	Sandbox()
	{
		PushLayer(new RenderLayer);
	}

	~Sandbox()
	{

	}

private:

};

Motus::Application* Motus::CreateApplication()
{
	return new Sandbox();
}