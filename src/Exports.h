#pragma once

#if defined(OS_WINDOWS)
	#if defined(ZIP_DLL)
		#if ZIP_DLL
			#define API_ZIP __declspec(dllexport)
		#else
			#define API_ZIP __declspec(dllimport)
		#endif
	#else
		#define API_ZIP
	#endif
#elif defined(OS_LINUX)
	#define API_ZIP
#endif