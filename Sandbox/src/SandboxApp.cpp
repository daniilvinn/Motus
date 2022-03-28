#include <Motus.h>
#include <imgui/imgui.h>

class ExampleLayer : public Motus::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {};

	void OnUpdate() override 
	{
		// Render
	}

	void OnImGuiRender() override 
	{
		// ImGui Render
	}

	void OnEvent(Motus::Event& event) override {
		
	}
};

class Sandbox : public Motus::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Motus::Application* Motus::CreateApplication()
{
	return new Sandbox();
}
