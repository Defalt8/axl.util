#include "allocators.hpp"
#include <malloc.h>

namespace axl {
namespace util {
namespace ds {
namespace Allocators {

//
// Malloc
//

template <typename E>
E* Malloc<E>::allocate(size_t count)
{
	if(count == 0U) return (E*)0;
	return (E*)::malloc(count * sizeof(E));
}
template <typename E>
E* Malloc<E>::reallocate(E* mem, size_t count, size_t old_count)
{
	if(count == 0U)
	{
		deallocate(mem);
		return (E*)0;
	}
	return (E*)::realloc(mem, count * sizeof(E));
}
template <typename E>
void Malloc<E>::deallocate(void* mem)
{
	::free(mem);
}

//
// Calloc
//

template <typename E>
E* Calloc<E>::allocate(size_t count)
{
	if(count == 0U) return (E*)0;
	return (E*)::calloc(count, sizeof(E));
}
template <typename E>
E* Calloc<E>::reallocate(E* mem, size_t count, size_t old_count)
{
	if(count == 0U)
	{
		deallocate(mem);
		return (E*)0;
	}
	return (E*)::realloc(mem, count * sizeof(E));
}
template <typename E>
void Calloc<E>::deallocate(void* mem)
{
	::free(mem);
}

//
// New
//

template <typename E>
E* New<E>::allocate(size_t count)
{
	if(count == 0U) return (E*)0;
	return new E[count];
}
template <typename E>
E* New<E>::reallocate(E* mem, size_t new_count, size_t old_count)
{
	if(new_count == 0U)
	{
		deallocate(mem);
		return (E*)0;
	}
	E* new_mem = new E[new_count];
	if(!new_mem) return (E*)0;
	size_t min_count = new_count <= old_count ? new_count : old_count;
	if(mem)
	{
		for(size_t i = 0; i < min_count; ++i)
			new_mem[i] = mem[i];
		delete[](mem);
	}
	return new_mem;
}
template <typename E>
void New<E>::deallocate(void* mem)
{
	if(mem) delete[]((E*)mem);
}

} // axl::util::Allocators
} // axl::util::ds
} // axl::util
} // axl