#include "Core.h"

#pragma once
namespace SASY {
	class SASY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
	
}

