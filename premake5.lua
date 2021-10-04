--premake5.lua

workspace "GamePhysics"
	architecture "x64"
	configurations {"Debug", "Release"}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "GamePhysics"
	cppdialect "c++17"
	location "GamePhysics"
	kind "consoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"Dependencies/RayLib/include"
	}

	libdirs --library directories
	{
		"Dependencies/RayLib/lib"
	}

	links
	{
		"raylibdll.lib",
		"opengl32.lib"
	}

	defines
	{
		"USE_LIBTYPE_SHARED",
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter"configurations:Debug"
		runtime "Debug"
		symbols "On"

		filter "configurations:Release"
		optimize "On"