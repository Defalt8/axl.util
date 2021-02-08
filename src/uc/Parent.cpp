#include <stdio.h>
#include <axl.util/uc/Parent.hpp>
#include <axl.util/uc/Child.hpp>

namespace axl {
namespace util {
namespace uc {

Parent::Parent()
{}

Parent::~Parent()
{
	Parent::removeChildren();
}

bool Parent::addChild(Child* child)
{
	if(!child) return false;
	for(auto it = Parent::m_children.first(); it != Parent::m_children.end(); ++it)
	{
		if((*it) == child) return true;
	}
	return child->onAddition(this) && Parent::m_children.insertLast(child);
}

bool Parent::removeChild(Child* child)
{
	if(!child || !Parent::m_children.remove(child)) return false;
	child->onRemoval(this);
	return true;
}

void Parent::removeChildren()
{
	while(!Parent::m_children.isEmpty())
	{
		Child* child = Parent::m_children.removeFirst();
		if(child)
		{
			child->onRemoval(this);
		}
	}
}

const axl::util::ds::UniList<Child*>& Parent::getChildren() const
{
	return Parent::m_children;
}

} // axl::util::uc
} // axl::util
} // axl
