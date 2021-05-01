#pragma once
#include "lib.hpp"
#include "types.hpp"
#include "ds/Array.hpp"
#include "ds/List.hpp"

namespace axl {
namespace util {

class AXLUTILCXXAPI Serial;

class AXLUTILCXXAPI Protocol
{
	public:
		Protocol();
		virtual ~Protocol();
		virtual ds::Array<byte, axl::util::ds::Allocators::Malloc<byte>> serialize(const Serial& serial) const = 0;
		virtual bool deserialize(Serial& serial, const ds::Array<byte, axl::util::ds::Allocators::Malloc<byte>>& serial_data) const = 0;
};

} // axl.util
} // axl
