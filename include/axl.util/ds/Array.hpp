#pragma once
#include <initializer_list>
#include "../types.hpp"
#include "../allocators.hpp"

namespace axl {
namespace util {
namespace ds {

// A template array class of an element type <E> and an allocator class <Allocator> with default allocator type New.
template <typename E, class Allocator = Allocators::New<E>>
class Array
{
public:
	virtual ~Array();
	template <typename T = E>
	Array(const std::initializer_list<T>& list);
	Array(size_t count = 0U);
	Array(const Array<E,Allocator>& array);
	template <typename T, class V = Allocator>
	Array(const Array<T,V>& array);
#	if __cplusplus >= 201103L
	Array(Array<E,Allocator>&& array);
#	endif
	Array(const E* array_ptr, size_t count, size_t offset = 0U);
public:
	template <typename T = E>
	Array<E,Allocator>& operator=(const std::initializer_list<T>& list);
	template <typename T = E, class V = Allocator>
	Array<E,Allocator>& operator=(const Array<T,V>& array);
#	if __cplusplus >= 201103L
	Array<E,Allocator>& operator=(Array<E,Allocator>&& array);
#	endif
	E& operator[](size_t index);
	const E& operator[](size_t index) const;
	template <typename T = E, class V = Allocator>
	bool operator==(const Array<T,V>& array) const;
	template <typename T = E, class V = Allocator>
	bool operator!=(const Array<T,V>& array) const;
public:
	void destroy();
	bool resize(size_t count);
	template <typename T = E>
	bool resize(size_t count, const T& fill_value);
	bool set(E value, size_t count = -1, size_t offset = 0U);
	size_t count() const;
	E* array();
	const E* array() const;
public:
	template <typename T = E>
	static E* Copy(E* dest, const T* src, size_t count, size_t offset = 0U);
private:
	size_t m_count;
	E* m_arr_ptr;
};

} // axl::util::ds
} // axl::util
} // axl

#include "Array.inl"
