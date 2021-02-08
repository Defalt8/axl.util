#include <stdio.h>
#include <axl.util/uc/Object.hpp>

namespace axl {
namespace util {
namespace uc {

Object::Object() : m_created(false)
{}

Object::~Object()
{}

bool Object::create()
{
	if(!Object::m_created && this->icreate())
		Object::m_created = true;
	return Object::m_created;
}

bool Object::destroy()
{
	if(Object::m_created && this->idestroy())
		Object::m_created = false;
	return !Object::m_created;
}

bool Object::isCreated() const
{
	return this->m_created;
}

} // axl::util::uc
} // axl::util
} // axl
