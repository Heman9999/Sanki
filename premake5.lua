workspace "SASY"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SASY"
	location "SASY"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:window"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines{
			"SY_PLATFROM_WINDOW",
			"SY_BUILD_DILL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/".. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SY_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "SY_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++14"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include",
		"SASY/Src"
	}
	links{
		"SASY"
	}

	filter "system:window"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines{
			"SY_PLATFROM_WINDOW"
		}

	filter "configurations:Debug"
		defines "SY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SY_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "SY_DIST"
		symbols "On"
