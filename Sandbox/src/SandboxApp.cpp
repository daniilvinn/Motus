#include <Motus.h>

class ExampleLayer : public Motus::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {};

	void OnUpdate() override 
	{
		
	}

	void OnEvent(Motus::Event& event) override {
		MT_CLIENT_INFO("ExampleLayer: {0}", event.GetLogInfo());
	}
};

class Sandbox : public Motus::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Motus::ImGUILayer());
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
