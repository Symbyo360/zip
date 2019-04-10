zip = path.getabsolute(".")

function use_zip()
	includedirs "%{zip}/src"
	links "zip"
end

project "zip"
	language "C"
	kind "SharedLib"

	files
	{
		"src/**.h",
		"src/**.c"
	}

	includedirs
	{
		"src"
	}

	defines
	{
		"ZIP_DLL"
	}
