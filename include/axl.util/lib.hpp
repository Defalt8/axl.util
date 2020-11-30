#pragma once

#if defined(LIBAXLUTIL_SHARED) // shared
#	ifdef WIN32
#		ifdef LIBAXLUTIL_BUILD // export
#			define AXLUTILSAPI extern __declspec(dllexport)
#			define AXLUTILSCXXAPI __declspec(dllexport)
#		else // import
#			define AXLUTILSAPI extern __declspec(dllimport)
#			define AXLUTILSCXXAPI __declspec(dllexport)
#		endif
#	else // other
#		define AXLUTILSAPI extern
#		define AXLUTILSCXXAPI
#	endif
#else // static or other
#	define AXLUTILSAPI extern
#	define AXLUTILSCXXAPI
#endif

namespace axl {
namespace util {
namespace lib {

typedef enum LibraryType {
	LT_STATIC,
	LT_SHARED
} LibraryType;

typedef enum BuildType {
	BT_DEBUG,
	BT_RELEASE,
	BT_OTHER
} BuildType;

typedef struct Version
{
	unsigned short major;
	unsigned short minor;
	unsigned short patch;
} Version;

AXLUTILSAPI const Version VERSION;
AXLUTILSAPI const LibraryType LIBRARY_TYPE;
AXLUTILSAPI const BuildType BUILD_TYPE;

} // namespace axl.util.lib	
} // namespace axl.util	
} // namespace axl
