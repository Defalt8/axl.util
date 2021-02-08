#pragma once
#include "../lib.hpp"

namespace axl {
namespace util {
namespace uc {

class AXLUTILCXXAPI Object
{
	public:
		Object();
		virtual ~Object();
		// checks if object is not created and invokes the pure virtual method 'icreate'.
		bool create();
		// checks if object is created and invokes the pure virtual method 'idestroy'.
		bool destroy();
		bool isCreated() const;
	protected:
		virtual bool icreate() = 0; // actual create method. *must implement in derived class.
		virtual bool idestroy() = 0; // actual destroy method. *must implement in derived class.
	private:
		bool m_created;
};

} // axl::util::uc
} // axl::util
} // axl
