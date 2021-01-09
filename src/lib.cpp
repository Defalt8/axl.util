#include <axl.util/lib.hpp>

namespace axl {
namespace util {
namespace lib {


const Version VERSION = { AXLUTIL_VERSION_MAJOR, AXLUTIL_VERSION_MINOR, AXLUTIL_VERSION_PATCH };

#if defined(AXLUTIL_SHARED)
const LibraryType LIBRARY_TYPE = LT_SHARED;
#elif defined(AXLUTIL_STATIC)
const LibraryType LIBRARY_TYPE = LT_STATIC;
#endif

#if defined(DEBUG)
const BuildType BUILD_TYPE = BT_DEBUG;
#elif defined(NDEBUG)
const BuildType BUILD_TYPE = BT_RELEASE;
#else
const BuildType BUILD_TYPE = BT_OTHER;
#endif

} // namespace axl.util.lib	
} // namespace axl.util	
} // namespace axl
