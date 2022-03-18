workspace "Motus"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Motus/vendor/GLFW/include"
IncludeDir["Glad"] = "Motus/vendor/Glad/include"
IncludeDir["imgui"] = "Motus/vendor/imgui"

include "Motus/vendor/GLFW"
include "Motus/vendor/Glad"
include "Motus/vendor/imgui"

project "Motus"
	location "Motus"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "motus_pch.h"
	pchsource "Motus/src/motus_pch.cpp"

	flags {
		"MultiProcessorCompile"
	}

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}"
	}

	links 
	{
		"Glad",
		"GLFW",
		"imgui",
		"opengl32.lib"
	}

	defines 
	{
		"MT_STATIC",
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"MT_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "MT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MT_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	flags {
		"MultiProcessorCompile"
	}

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Motus/vendor/spdlog/include",
		"Motus/src",
		"Motus/vendor"
	}

	links 
	{
		"Motus"
	}

	defines 
	{
		"MT_STATIC"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"MT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MT_DIST"
		optimize "On"