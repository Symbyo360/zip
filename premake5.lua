zip_path = path.getabsolute(".")

function use_zip()
	includedirs "%{zip_path}/src"
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
