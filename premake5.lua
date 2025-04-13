workspace "SnakeRay"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

filter "system:windows"
    defines { "CloseWindow=Raylib_CloseWindow"}
filter {}

project "raylib"
    kind "StaticLib"
    language "C"
    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    files{
        "3rdParty/raylib/src/*.c",
        "3rdParty/raylib/src/*h"
    }

    includedirs{
        "3rdParty/raylib/src",
        "3rdParty/raylib/src/external/glfw/include"
    }

    filter "system:windows"
        defines { "PLATFORM_WINDOWS", "PLATFORM_DESKTOP" }
        links { "winmm", "opengl32", "gdi32" }
    filter {}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        defines { "NDEBUG" }

    filter {}

project "SnakeRay"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    files {
        "src/**.cpp",
        "src/**.h",
        "assets/*.wav",
        "assets/sfx/*.wav"
    }

    includedirs {
        "3rdParty/raylib/src",
        "3rdParty/raylib/src/external/glfw/include",
        "src",
        "assets"
    }

    links {
        "raylib"
    }

    filter "system:Windows"
        defines { "PLATFORM_WINDOWS" }
        postbuildcommands {
            'if not exist "%{cfg.targetdir}\\assets" mkdir "%{cfg.targetdir}\\assets"',
            'xcopy "%{wks.location}assets" "%{cfg.targetdir}\\assets" /e /y /i'
        }

    filter {}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "DEBUG" }
    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        defines { "NDEBUG" }
    filter{}