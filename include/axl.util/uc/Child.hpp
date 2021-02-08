#pragma once
#include "../lib.hpp"

namespace axl {
namespace util {
namespace uc {

class AXLUTILCXXAPI Parent;

class AXLUTILCXXAPI Child
{
	public:
		Child();
		virtual ~Child();
		// invokes parent's addChild method on itself.
		bool addTo(Parent* parent);
		// removes itself from its parent.
		bool removeFromParent();
	protected:
		// called just before addition.
		virtual bool onAddition(Parent* parent);
		// called just before removal.
		virtual void onRemoval(Parent* parent);
	public:
		Parent*const& getParent() const;
	private:
		Parent* m_parent;
		friend class Parent;
};

} // axl::util::uc
} // axl::util
} // axl
