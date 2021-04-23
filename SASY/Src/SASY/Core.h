#pragma once


#ifdef SY_PLATFROM_WINDOW
#ifdef SY_BUILD_DILL
#define SASY_API _declspec(dllexport)
#else
#define SASY_API _declspec(dllimport)
#endif // HZ_BUILD_DILL
#else
#error hazel only support window
#endif // HZ_PLATFROM_WINDOW
