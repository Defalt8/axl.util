#pragma once
#include "lib.hpp"
#include "types.hpp"
#include "ds/Array.hpp"
#include "ds/List.hpp"

namespace axl {
namespace util {
 
struct AXLUTILCXXAPI SerialObjectInfo
{
	void* mem_ptr;
	uint8 references;
	uint32 size;
	uint32 object_id;
	SerialObjectInfo(void* mem_ptr = 0, uint8 references = 0, uint32 size = 0U, uint32 object_id = 0U);
	bool operator==(const SerialObjectInfo& serial_object_info) const;
};

template class AXLUTILCXXAPI axl::util::ds::UniList<SerialObjectInfo>;

class AXLUTILCXXAPI Serial
{
	public:
		Serial();
		const axl::util::ds::UniList<SerialObjectInfo>& getObjectRegistry() const;
		bool setPointer(uint32 object_id, void* new_ptr);
		bool setReferences(uint32 object_id, uint8 references);
		bool setSize(uint32 object_id, uint32 size);
		bool setId(uint32 object_id, uint32 new_id);
		virtual bool onSerialize(SerialObjectInfo& object_info);
		virtual bool onDeserialize(SerialObjectInfo object_info);
	protected:
		bool Register(void* mem_ptr, uint8 references, uint32 size, uint32 object_id);
		bool Unregister(void* mem_ptr, uint8 references, uint32 size, uint32 object_id);
	private:
		axl::util::ds::UniList<SerialObjectInfo> m_object_registry;
};

} // axl.util
} // axl
