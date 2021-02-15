
#include <ctime>
#include <axl.util/uc/Time.hpp>

namespace axl {
namespace util {
namespace uc {

Time::Time() :
	m_checkpoint(0)
{
	this->set();
}
void Time::set()
{
	m_checkpoint = clock();
}
void Time::setFromReference(const Time& reference)
{
	m_checkpoint = this->m_checkpoint + (clock() - reference.m_checkpoint);
}
float Time::deltaTimef() const
{
	return ((float)clock() - m_checkpoint) / 1000.0f;
}
double Time::deltaTime() const
{
	return ((double)clock() - m_checkpoint) / 1000.0;
}
Time::millis_t Time::deltaTimei() const
{
	return ((millis_t)clock() - m_checkpoint) / 1000;
}
float Time::deltaTimeM() const
{
	return ((float)clock() - m_checkpoint);
}
Time::millis_t Time::deltaTimeMi() const
{
	return ((millis_t)clock() - m_checkpoint);
}

} // axl::util::uc
} // axl::util
} // axl
