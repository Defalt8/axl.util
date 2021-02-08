#include <stdio.h>
#include <axl.util/uc/Parent.hpp>
#include <axl.util/uc/Child.hpp>

namespace axl {
namespace util {
namespace uc {

Child::Child() : m_parent(0)
{}

Child::~Child()
{
	Child::removeFromParent();
}

bool Child::addTo(Parent* parent)
{
	if(!parent) return false;
	if(parent == Child::m_parent) return true;
	if(Child::m_parent) Child::m_parent->removeChild(this);
	return parent->addChild(this);
}

bool Child::removeFromParent()
{
	if(!Child::m_parent) return false;
	return Child::m_parent->removeChild(this);
}

bool Child::onAddition(Parent* parent)
{
	this->m_parent = parent;
	return true;
}

void Child::onRemoval(Parent* parent)
{
	this->m_parent = (Parent*)0;
}

Parent*const& Child::getParent() const
{
	return Child::m_parent;
}

} // axl::util::uc
} // axl::util
} // axl
