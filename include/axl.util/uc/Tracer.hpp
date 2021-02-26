#pragma once
#include "../lib.hpp"

namespace axl {
namespace util {
// Utility classes
namespace uc {

class AXLUTILCXXAPI Tracer
{
public:
	typedef int value_t;
	typedef unsigned long long id_t;
public:
	virtual ~Tracer();
	Tracer(value_t value = value_t());
	Tracer(const Tracer& tracer);
#	if __cplusplus >= 201103L
	Tracer(Tracer&& tracer);
#	endif
public:
	Tracer& operator=(const Tracer& tracer);
	Tracer& operator=(value_t value);
#	if __cplusplus >= 201103L
	Tracer& operator=(Tracer&& tracer);
#	endif
	bool operator==(const Tracer& tracer) const;
	bool operator!=(const Tracer& tracer) const;
public:
	static void Reset();
	static const id_t Top();
	static const id_t Active();
public:
	const id_t id;
	value_t value;
private:
	static id_t S_TOP;
	static id_t S_ACTIVE;
};

} // axl::util::uc
} // axl::util
} // axl

// #include "Tracer.inl"
