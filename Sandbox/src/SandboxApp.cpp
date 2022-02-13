#include <Motus.h>


class Sandbox : public Motus::Application {
public:
	Sandbox()
	{
		
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
