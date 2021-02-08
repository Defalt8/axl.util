#pragma once
#include "../lib.hpp"
#include "../ds/List.hpp"

namespace axl {
namespace util {
namespace uc {

class AXLUTILCXXAPI Child;

class AXLUTILCXXAPI Parent
{
	public:
		Parent();
		virtual ~Parent();
		// adds child to this parent object.
		bool addChild(Child* child);
		// removes child from this parent object.
		bool removeChild(Child* child);
		// removes all children from this parent object.
		void removeChildren();
		// returns constant reference to the children unidirectional list.
		const axl::util::ds::UniList<Child*>& getChildren() const;
	private:
		axl::util::ds::UniList<Child*> m_children;
};

} // axl::util::uc
} // axl::util
} // axl
