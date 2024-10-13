workspace "LearnSQL"
	architecture "x64"
	startproject "LearnSQL"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "LearnSQL"
	location "LearnSQL"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/source/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/include",
		"./ExternalLibraries/sqlite3",
	}

	libdirs 
	{
		"./ExternalLibraries/sqlite3"
	}
	
	links
	{
		"sqlite3"
	}


	filter "configurations:Debug"
		defines "NG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NG_RELEASE"
		runtime "Release"
		optimize "On"

