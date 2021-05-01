#pragma once
#include "../lib.hpp"
#include "../types.hpp"
#include "../ds/Array.hpp"
#include "../ds/List.hpp"
#include "../Protocol.hpp"

namespace axl {
namespace util {
namespace protocol {

class AXLUTILCXXAPI V0 : public axl::util::Protocol
{
	public:
		V0();
		virtual ~V0();
		virtual ds::Array<byte, axl::util::ds::Allocators::Malloc<byte>> serialize(const Serial& serial) const;
		virtual bool deserialize(Serial& serial, const axl::util::ds::Array<byte, axl::util::ds::Allocators::Malloc<byte>>& serial_data) const;
};

} // axl.util.protocol
} // axl.util
} // axl
