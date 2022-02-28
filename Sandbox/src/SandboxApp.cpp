#include <Motus.h>

class ExampleLayer : public Motus::Layer {
public:
	ExampleLayer() : Layer("Example Layer") {};

	void OnUpdate() override 
	{
		MT_CLIENT_INFO("Example layer is on update.");
	}

	void OnEvent(Motus::Event& event) override {
		MT_CLIENT_INFO("{0}", event.GetLogInfo());
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
