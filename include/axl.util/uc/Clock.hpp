#pragma once
#include "../lib.hpp"

namespace axl {
namespace util {
namespace uc {

class AXLUTILCXXAPI Clock
{
	public: typedef unsigned long millis_t;
	public:
		Clock(millis_t interval);
		// Checks if <interval> amount of time has passed since last set call.
		bool check() const;
		// Updates the clock to the current time.
		void set();
		// Checks and update the clock.
		// If <first_time> is true, then it will return true for the fist call to
		//   checkAndSet since creation or last reset. 
		bool checkAndSet(bool first_time);
		// Resets all the clock states.
		void reset();
		// Clock time interval in milliseconds.
		millis_t interval;
	private:
		bool m_first_time;
		millis_t m_clock;
};

} // axl::util::uc
} // axl::util
} // axl
