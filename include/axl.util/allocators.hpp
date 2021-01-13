#pragma once
#include "../types.hpp"

namespace axl {
namespace util {
namespace ds {
namespace Allocators {

template <typename E>
class Malloc
{
public:
	static E* allocate(size_t count);
	static E* reallocate(E* mem, size_t new_count, size_t old_count = -1);
	static void deallocate(void* mem);
private:
	Malloc();
	~Malloc();
};

template <typename E>
class Calloc
{
public:
	static E* allocate(size_t count);
	static E* reallocate(E* mem, size_t new_count, size_t old_count = -1);
	static void deallocate(void* mem);
private:
	Calloc();
	~Calloc();
};

template <typename E>
class New
{
public:
	static E* allocate(size_t count);
	static E* reallocate(E* mem, size_t new_count, size_t old_count = -1);
	static void deallocate(void* mem);
private:
	New();
	~New();
};

} // axl::util::Allocators
} // axl::util::ds
} // axl::util
} // axl

#include "allocators.inl"
