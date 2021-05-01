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

Serial::ObjectInfo::ObjectInfo(void* _mem_ptr, uint32 _size, uint32 _object_id) :
	mem_ptr(_mem_ptr),
	size(_size),
	object_id(_object_id)
{}

bool Serial::ObjectInfo::operator==(const ObjectInfo& object_info) const
{
	return this->mem_ptr == object_info.mem_ptr &&
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

bool Serial::Register(void* mem_ptr, uint32 size, uint32 object_id)
{
	return m_object_registry.insertLast(ObjectInfo(mem_ptr, size, object_id));
}
bool Serial::Unregister(void* mem_ptr, uint32 size, uint32 object_id)
{
	return m_object_registry.remove(ObjectInfo(mem_ptr, size, object_id));

}

} // axl.util
} // axl
