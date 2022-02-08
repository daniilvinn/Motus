#include <iostream>

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

int main() {
	
	Sandbox sandbox;
	sandbox.Run();


	system("pause");
}