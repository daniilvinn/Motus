#include <Motus.h>

class ExampleLayer : public Motus::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {};

	void OnUpdate() override 
	{
		
	}

	void OnEvent(Motus::Event& event) override {
		
	}
};

class Sandbox : public Motus::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Motus::ImGuiLayer());
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
