#include <axl.util/lib.hpp>

namespace axl {
namespace util {
namespace lib {


AXLUTILSAPI const Version VERSION = { LIBAXLUTIL_VERSION_MAJOR, LIBAXLUTIL_VERSION_MINOR, LIBAXLUTIL_VERSION_PATCH };

#if defined(LIBAXLUTIL_SHARED)
AXLUTILSAPI const LibraryType LIBRARY_TYPE = LT_SHARED;
#elif defined(LIBAXLUTIL_STATIC)
AXLUTILSAPI const LibraryType LIBRARY_TYPE = LT_STATIC;
#endif

#if defined(DEBUG)
AXLUTILSAPI const BuildType BUILD_TYPE = BT_DEBUG;
#elif defined(NDEBUG)
AXLUTILSAPI const BuildType BUILD_TYPE = BT_RELEASE;
#else
AXLUTILSAPI const BuildType BUILD_TYPE = BT_OTHER;
#endif

} // namespace axl.util.lib	
} // namespace axl.util	
} // namespace axl
