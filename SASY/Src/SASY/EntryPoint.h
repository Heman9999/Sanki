#pragma once

#ifdef  SY_PLATFROM_WINDOW
extern SASY::Application* SASY::CreateApplication();

int main(int args, char** argv) {
	SASY::Log::Init();
	SY_CORE_WARN("Initialized Log!");
	SY_CLIENT_INFO("Hello!");
	auto app = SASY::CreateApplication();
	app->Run();

	delete app;
}
#endif //  SY_PLATFROM_WINDOW
