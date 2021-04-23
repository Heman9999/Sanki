#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SASY {
	class SASY_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//Core Log Macros
#define SY_CORE_ERROR(...)    ::SASY::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SY_CORE_INFO(...)     ::SASY::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SY_CORE_WARN(...)     ::SASY::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SY_CORE_TRACE(...)    ::SASY::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SY_CORE_FATAL(...)    ::SASY::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define SY_CLIENT_ERROR(...)  ::Log::GetClientLogger()->error(__VA_ARGS__)
#define SY_CLIENT_INFO(...)   ::SASY::Log::GetClientLogger()->info(__VA_ARGS__)
#define SY_CLINE_WARN(...)    ::SASY::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SY_CLIENT_TRACE(...)  ::SASY::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SY_CLIENT_FATAL(...)  ::SASY::Log::GetClientLogger()->fatel(__VA_ARGS__)

