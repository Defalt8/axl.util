#include <axl.util/uc/Tracer.hpp>

namespace axl {
namespace util {
namespace uc {

Tracer::~Tracer()
{
	--Tracer::S_ACTIVE;
}

Tracer::Tracer(value_t p_value) :
	id(++Tracer::S_TOP),
	value(p_value)
{
	++Tracer::S_ACTIVE;
}

Tracer::Tracer(const Tracer& tracer) :
	id(++Tracer::S_TOP),
	value(tracer.value)
{
	++Tracer::S_ACTIVE;
}

#if __cplusplus >= 201103L
Tracer::Tracer(Tracer&& tracer) :
	id(tracer.id),
	value(tracer.value)
{}
#endif

Tracer& Tracer::operator=(const Tracer& tracer)
{
	this->value = tracer.value;
	return *this;
}

Tracer& Tracer::operator=(Tracer::value_t p_value)
{
	this->value = p_value;
	return *this;
}

#if __cplusplus >= 201103L
Tracer& Tracer::operator=(Tracer&& tracer)
{
	this->id = tracer.id;
	this->value = tracer.value;
	return *this;
}
#endif

bool Tracer::operator==(const Tracer& tracer) const
{
	return this->value == tracer.value;
}

bool Tracer::operator!=(const Tracer& tracer) const
{
	return this->value != tracer.value;
}

void Tracer::Reset()
{
	Tracer::S_TOP = 0;
	Tracer::S_ACTIVE = 0;
}

const Tracer::id_t Tracer::Top()
{
	return Tracer::S_TOP;
}
const Tracer::id_t Tracer::Active()
{
	return Tracer::S_ACTIVE;
}

Tracer::id_t Tracer::S_TOP = 0;
Tracer::id_t Tracer::S_ACTIVE = 0;


} // axl::util::uc
} // axl::util
} // axl
