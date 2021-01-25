
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
float Time::deltaTime() const
{
	return ((float)clock() - m_checkpoint) / 1000.0f;
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