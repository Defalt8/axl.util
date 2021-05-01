#pragma once
#include "types.hpp"
#include "lib.hpp"

namespace axl {
namespace util {

template <typename T, typename U>
T& refer(U* u) { return *((T*)u); }

uint16 AXLUTILAPI htons(uint16 x);
uint32 AXLUTILAPI htonl(uint32 x);

} // axl.util
} // axl
