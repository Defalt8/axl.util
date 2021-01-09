#pragma once

#if defined(AXLUTIL_SHARED) // shared
#	ifdef WIN32
#		ifdef AXLUTIL_BUILD // export
#			define AXLUTILAPI extern __declspec(dllexport)
#			define AXLUTILCXXAPI __declspec(dllexport)
#		else // import
#			define AXLUTILAPI extern __declspec(dllimport)
#			define AXLUTILCXXAPI __declspec(dllexport)
#		endif
#	else // other
#		define AXLUTILAPI extern
#		define AXLUTILCXXAPI
#	endif
#else // static or other
#	define AXLUTILAPI extern
#	define AXLUTILCXXAPI
#endif

namespace axl {
namespace util {
namespace lib {

typedef enum _LibraryType {
	LT_STATIC,
	LT_SHARED
} LibraryType;

typedef enum _BuildType {
	BT_DEBUG,
	BT_RELEASE,
	BT_OTHER
} BuildType;

typedef struct _Version
{
	unsigned short major;
	unsigned short minor;
	unsigned short patch;
} Version;

AXLUTILAPI const Version VERSION;
AXLUTILAPI const LibraryType LIBRARY_TYPE;
AXLUTILAPI const BuildType BUILD_TYPE;

} // namespace axl.util.lib	
} // namespace axl.util	
} // namespace axl
