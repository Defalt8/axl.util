#include <axl.util/utils.hpp>

namespace axl {
namespace util {


uint16 htons(uint16 x)
{
#if AXLUTIL_LITTLE_ENDIAN
    byte *s = (byte *)&x;
    return (uint16)(s[0] << 8 | s[1]);
#else
    return x;
#endif
}

uint32 htonl(uint32 x)
{
#if AXLUTIL_LITTLE_ENDIAN
    byte *s = (byte *)&x;
    return (uint32)(s[0] << 24 | s[1] << 16 | s[2] << 8 | s[3]);
#else
    return x;
#endif
}

} // axl.util
} // axl


