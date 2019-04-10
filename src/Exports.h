#pragma once

#ifdef OS_WINDOWS
#ifdef ZIP_DLL
	#define API_ZIP __declspec(dllexport)
#else
	#define API_ZIP __declspec(dllimport)
#endif
#endif

#ifdef OS_LINUX
	#define API_ZIP
#endif