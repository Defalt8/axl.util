#include <axl.util/lib.hpp>
#include <axl.util/Serial.hpp>
#include <axl.util/Protocol.hpp>
#include <axl.util/protocols/V0.hpp>
#include <axl.util/utils.hpp>

namespace axl {
namespace util {
namespace protocol {

V0::V0() : axl::util::Protocol()
{}

V0::~V0()
{}

ds::Array<byte, axl::util::ds::Allocators::Malloc<byte>> V0::serialize(const Serial& serial) const
{
	ds::Array<byte> serial_data;
	const axl::util::ds::UniList<axl::util::Serial::ObjectInfo>& object_registry = serial.getObjectRegistry();
	size_t total_data_size = 0U, total_size = 0U, object_count = 0U;
	{ // determine the total size required
		ds::UniList<Serial::ObjectInfo>::Iterator it = object_registry.first();
		while(it.isNotNull())
		{
			total_data_size += (*it).size;
			++object_count;
			++it;
		}
		total_size = 4 + // uint32 for total serial data size
			4 + // uint32 for object count
			object_count * // data size of each object-info
				(
					4 +	// uint32 for object data size
					4	// uint32 for object data offset
				) +
			total_data_size; // total data size
			
	}
	if(serial_data.resize(total_size))
	{
		// serialize the objects
		// write header
		refer<uint32>(&serial_data[0]) = htonl(total_size);
		refer<uint32>(&serial_data[4]) = htonl(object_count);
		size_t object_index = 0, header_size = (8 + object_count * 8), size_accum = 0U;
		axl::util::ds::UniList<Serial::ObjectInfo>::Iterator it = object_registry.first();
		while(it.isNotNull())
		{
			refer<uint32>(&serial_data[8 + object_index * 8]) = htonl((*it).size);
			refer<uint32>(&serial_data[12 + object_index * 8]) = htonl(header_size + size_accum);
			size_accum += (*it).size;
			++object_index;
			++it;
		}
		object_index = 0;
		it = object_registry.first();
		while(it.isNotNull())
		{
			size_t offset = htonl(refer<uint32>(&serial_data[12 + object_index * 8]));
			serial_data.copy((byte*)((*it).mem_ptr), (*it).size, offset);
			++object_index;
			++it;
		}
	}
	return serial_data;
}

bool V0::deserialize(Serial& serial, const axl::util::ds::Array<byte, axl::util::ds::Allocators::Malloc<byte>>& serial_data) const
{
	size_t total_data_size = 0U, total_size = 0U, object_count = 0U;
	const axl::util::ds::UniList<axl::util::Serial::ObjectInfo>& object_registry = serial.getObjectRegistry();
	{ // determine the total size required
		ds::UniList<Serial::ObjectInfo>::Iterator it = object_registry.first();
		while(it.isNotNull())
		{
			total_data_size += (*it).size;
			++object_count;
			++it;
		}
		total_size = 4 + // uint32 for total serial data size
			4 + // uint32 for object count
			object_count * // data size of each object-info
				(
					4 +	// uint32 for object data size
					4	// uint32 for object data offset
				) +
			total_data_size; // total data size
			
	}
	if(serial_data.count() < total_size) return false;
	// read header
	uint32 r_total_size = htonl(refer<uint32>(&serial_data[0]));
	uint32 r_object_count = htonl(refer<uint32>(&serial_data[4]));
	if(r_total_size < total_size || r_object_count != object_count) return false;
	size_t object_index = 0, header_size = (8 + object_count * 8);
	ds::UniList<Serial::ObjectInfo>::Iterator it = object_registry.first();
	while(it.isNotNull())
	{
		size_t size = htonl(refer<uint32>(&serial_data[8 + object_index * 8]));
		size_t offset = htonl(refer<uint32>(&serial_data[12 + object_index * 8]));
		if(size != (*it).size) return false;
		axl::util::ds::Array<byte>::Copy((byte*)((*it).mem_ptr), &serial_data[offset], size, 0);
		++object_index;
		++it;
	}
	return true;
}

} // axl.util.protocol
} // axl.util
} // axl
