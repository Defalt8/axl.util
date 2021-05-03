#include <axl.util/lib.hpp>
#include <axl.util/Serial.hpp>
#include <axl.util/utils.hpp>

template <typename T, typename U>
T& refer(U* u)
{
	return *((T*)u);
}

namespace axl {
namespace util {

/////
/// Serial::ObjectInfo
//

Serial::ObjectInfo::ObjectInfo(void* _mem_ptr, uint8 _references, uint32 _size, uint32 _object_id) :
	mem_ptr(_mem_ptr),
	references(_references),
	size(_size),
	object_id(_object_id)
{}

bool Serial::ObjectInfo::operator==(const ObjectInfo& object_info) const
{
	return this->mem_ptr == object_info.mem_ptr &&
		this->references == object_info.references &&
		this->size == object_info.size &&
		this->object_id == object_info.object_id;
}

/////
/// Serial
//

Serial::Serial() :
	m_object_registry()
{}
const axl::util::ds::UniList<Serial::ObjectInfo>& Serial::getObjectRegistry() const
{
	return this->m_object_registry;
}
bool Serial::setPointer(uint32 object_id, void* new_ptr)
{
	for(axl::util::ds::UniList<Serial::ObjectInfo>::Iterator it = m_object_registry.first(); it != m_object_registry.end(); ++it)
	{
		if((*it).object_id == object_id)
		{
			(*it).mem_ptr = new_ptr;
			return true;
		}
	}
	return false;
}
bool Serial::setReferences(uint32 object_id, uint8 references)
{
	for(axl::util::ds::UniList<Serial::ObjectInfo>::Iterator it = m_object_registry.first(); it != m_object_registry.end(); ++it)
	{
		if((*it).object_id == object_id)
		{
			(*it).references = references;
			return true;
		}
	}
	return false;
}
bool Serial::setSize(uint32 object_id, uint32 size)
{
	for(axl::util::ds::UniList<Serial::ObjectInfo>::Iterator it = m_object_registry.first(); it != m_object_registry.end(); ++it)
	{
		if((*it).object_id == object_id)
		{
			(*it).size = size;
			return true;
		}
	}
	return false;
}
bool Serial::setId(uint32 object_id, uint32 new_id)
{
	for(axl::util::ds::UniList<Serial::ObjectInfo>::Iterator it = m_object_registry.first(); it != m_object_registry.end(); ++it)
	{
		if((*it).object_id == object_id)
		{
			(*it).object_id = new_id;
			return true;
		}
	}
	return false;
}
bool Serial::onSerialize(Serial::ObjectInfo& object_info)
{
	return true;
}
bool Serial::onDeserialize(Serial::ObjectInfo object_info)
{
	return true;
}

bool Serial::Register(void* mem_ptr, uint8 references, uint32 size, uint32 object_id)
{
	return m_object_registry.insertLast(ObjectInfo(mem_ptr, references, size, object_id));
}
bool Serial::Unregister(void* mem_ptr, uint8 references, uint32 size, uint32 object_id)
{
	return m_object_registry.remove(ObjectInfo(mem_ptr, references, size, object_id));

}

} // axl.util
} // axl
