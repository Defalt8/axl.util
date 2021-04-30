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

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || \
	(defined(BYTE_ORDER) && BYTE_ORDER == LITTLE_ENDIAN) || \
    defined(__LITTLE_ENDIAN__) || \
    defined(_MSC_VER) || \
    defined(__ARMEL__) || \
    defined(__THUMBEL__) || \
    defined(__AARCH64EL__) || \
    defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__)
#	define AXLUTIL_LITTLE_ENDIAN 1
#else
#	define AXLUTIL_LITTLE_ENDIAN 0
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
