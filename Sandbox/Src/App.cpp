#include <SASY.h>

class Sandbox : public SASY::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

SASY::Application* SASY::CreateApplication() {
	return new Sandbox();
}
//
//int main() {
//	Sandbox* sand = new Sandbox();
//	sand->Run();
//
//	delete sand;
//}