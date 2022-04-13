#include <Motus.h>
#include <imgui/imgui.h>

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
	}

	void OnDetach() override
	{
		
	}


	void OnUpdate() override
	{
		m_Shader->Bind();

		Motus::Renderer::BeginScene();
		{
			if (Motus::Input::IsKeyPressed(MT_KEY_W)) {
				Motus::Renderer::Submit(m_VAO);
			}
		}
		Motus::Renderer::EndScene();

	}


	void OnImGuiRender() override {}

	void OnEvent(Motus::Event& event) override {}

private:
	std::shared_ptr<Motus::VertexBuffer> m_VBO;
	std::shared_ptr<Motus::IndexBuffer> m_IBO;
	std::shared_ptr<Motus::VertexArray> m_VAO;
	std::shared_ptr<Motus::Shader> m_Shader;
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
