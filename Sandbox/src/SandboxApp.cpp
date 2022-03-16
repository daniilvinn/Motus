#include <Motus.h>
#include <imgui/imgui.h>

class ExampleLayer : public Motus::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {};

	void OnUpdate() override 
	{
		
	}

	void OnImGuiRender() override {
		
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
	MT_CLIENT_INFO("Creating application...");
	return new Sandbox();
}
