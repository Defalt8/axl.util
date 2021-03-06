#pragma once
#include "../lib.hpp"

namespace axl {
namespace util {
namespace uc {

class AXLUTILCXXAPI Time
{
	public: typedef unsigned long millis_t;
	public:
		Time();
		// Updates the time checkpoint.
		void set();
		// Adds the current time minus the reference to the time checkpoint.
		void setFromReference(const Time& reference);
		// Returns the time difference till the last checkpoint in seconds.
		float deltaTimef() const;
		double deltaTime() const;
		millis_t deltaTimei() const;
		// Returns the time difference till the last checkpoint in milliseconds.
		float deltaTimeM() const;
		millis_t deltaTimeMi() const;
	private:
		millis_t m_checkpoint;
};

} // axl::util::uc
} // axl::util
} // axl
