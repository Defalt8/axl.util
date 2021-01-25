
#include <ctime>
#include <axl.util/uc/Clock.hpp>

namespace axl {
namespace util {
namespace uc {

Clock::Clock(millis_t _interval) :
	m_first_time(true),
	m_clock(0),
	interval(_interval)
{
	this->reset();
}
bool Clock::check() const
{
	return interval > 0 && (clock() - m_clock >= interval);
}

void Clock::set()
{
	this->m_clock = clock();
}

bool Clock::checkAndSet(bool first_time)
{
	if(interval == 0) return false;
	if(this->check())
	{
		this->set();
		return true;
	}
	if(this->m_first_time)
	{
		this->m_first_time = false;
		if(first_time) return true;
	}
	return false;
}

void Clock::reset()
{
	this->m_first_time = true;
	this->set();
}

} // axl::util::uc
} // axl::util
} // axl
