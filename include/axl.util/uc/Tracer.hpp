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
public:
	static void Reset();
public:
	const id_t id;
	value_t value;
public:
	const static id_t& TOP;
	const static id_t& ACTIVE;
private:
	static id_t S_TOP;
	static id_t S_ACTIVE;
};

} // axl::util::uc
} // axl::util
} // axl

// #include "Tracer.inl"
