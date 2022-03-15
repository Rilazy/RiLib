workspace "RiLib"
   configurations { "Debug", "Release" }
   platforms {"Win32", "Win64", "Linux-x86", "Linux-x64"}

   language "C++"
   cppdialect "C++20"
   systemversion "latest"

   files 
   {
      "%{prj.location}/src/**.h",
      "%{prj.location}/src/**.cpp",
   }

   includedirs
   {
      "*/src/include"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   filter "platforms:Win32"
      defines {"WINDOWS"}
      system("windows")
      architecture("x86")
   
   filter "platforms:Win64"
      defines {"WINDOWS"}
      system("windows")
      architecture("x86_64")

   filter "platforms:Linux-x86"
      defines {"LINUX"}
      system("linux")
      architecture("x86")
   
   filter "platforms:Linux-x64"
      defines {"LINUX"}
      system("linux")
      architecture("x86_64")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RiLog"
   staticruntime "On"
   location "%{prj.name}"
   kind "StaticLib"
   
   includedirs
   {
      "dependencies/spdlog/include"
   }

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("obj/" .. outputdir .. "/%{prj.name}")

project "RiMath"
   links {"RiLog"}
   staticruntime "On"
   location "%{prj.name}"
   kind "StaticLib"
   
   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("obj/" .. outputdir .. "/%{prj.name}")

project "RiCollections"
   links {"RiLog"}

   staticruntime "On"
   location "%{prj.name}"
   kind "StaticLib"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("obj/" .. outputdir .. "/%{prj.name}")

project "Sandbox"
   links {"RiLog", "RiMath", "RiCollections"}

   staticruntime "On"
   location "%{prj.name}"
   kind "ConsoleApp"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("obj/" .. outputdir .. "/%{prj.name}")
   

   