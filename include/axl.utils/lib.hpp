#pragma once

#if defined(MODULE)
	#ifdef WIN32
		#ifdef BUILD_MODULE
			#define AXLUTILSAPI extern __declspec(dllexport)
		#else
			#define AXLUTILSAPI extern __declspec(dllimport)
		#endif
	#else
		#define AXLUTILSAPI extern
	#endif
#elif defined(SHARED)
	#ifdef WIN32
		#ifdef BUILD_SHARED
			#define AXLUTILSAPI extern __declspec(dllexport)
		#else
			#define AXLUTILSAPI extern __declspec(dllimport)
		#endif
	#else
		#define AXLUTILSAPI extern
	#endif
#else
	#define AXLUTILSAPI extern
#endif

namespace axl {
namespace utils {
namespace lib {

struct Version
{
	short major;
	short minor;
	short patch;
};

AXLUTILSAPI Version version;

} // namespace axl.utils.lib	
} // namespace axl.utils	
} // namespace axl
