libzip = {}
libzip.path = path.getabsolute(".")

function libzip.use()
	includedirs "%{libzip.path}/src"
	links "zip"

	filter "platforms:shared"
		defines { "ZIP_DLL=0" }
	filter {}
end

project "zip"
	language "C"

	files
	{
		"src/**.h",
		"src/**.c"
	}

	includedirs
	{
		"src"
	}

	filter "platforms:static"
		kind "StaticLib"

	filter "platforms:shared"
		kind "SharedLib"
		defines { "ZIP_DLL=1" }

return libzip
