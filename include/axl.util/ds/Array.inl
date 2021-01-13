#include "Array.hpp"

namespace axl {
namespace util {
namespace ds {

template <typename E, class A>
Array<E,A>::~Array()
{
	this->destroy();
}

template <typename E, class A>
template <typename T>
Array<E,A>::Array(const std::initializer_list<T>& list) :
	m_count(0U),
	m_arr_ptr((E*)0)
{
	size_t a_count = list.size();
	if((this->m_arr_ptr = (E*)A::allocate(a_count)))
	{
		this->m_count = a_count;
		Copy(this->m_arr_ptr, list.begin(), this->m_count);
	}
}

template <typename E, class A>
Array<E,A>::Array(size_t count) :
	m_count(0U),
	m_arr_ptr((E*)0)
{
	if((this->m_arr_ptr = (E*)A::allocate(count)))
	{
		this->m_count = count;
	}
}

template <typename E, class A>
template <typename T, class V>
Array<E,A>::Array(const Array<T,V>& array) :
	m_count(0U),
	m_arr_ptr((E*)0)
{
	size_t a_count = array.count();
	if((this->m_arr_ptr = (E*)A::allocate(a_count)))
	{
		this->m_count = a_count;
		Array<E,A>::Copy<E,T>(this->m_arr_ptr, array.array(), a_count);
	}
}

#if __cplusplus >= 201103L
template <typename E, class A>
Array<E,A>::Array(Array<E,A>&& array) :
	m_count(array.m_count),
	m_arr_ptr((E*)array.m_arr_ptr)
{
	array.m_count = 0U;
	array.m_arr_ptr = (E*)0;
}
#endif

template <typename E, class A>
Array<E,A>::Array(const E* array_ptr, size_t count, size_t offset) :
	m_count(0U),
	m_arr_ptr((E*)0)
{
	if((this->m_arr_ptr = (E*)A::allocate(count)))
	{
		this->m_count = count;
		Array<E,A>::Copy(this->m_arr_ptr, array_ptr, count);
	}
}

template <typename E, class A>
template <typename T>
Array<E,A>& Array<E,A>::operator=(const std::initializer_list<T>& list)
{
	this->destroy();
	size_t a_count = list.size();
	if((this->m_arr_ptr = (E*)A::allocate(a_count)))
	{
		this->m_count = a_count;
		Copy(this->m_arr_ptr, list.begin(), a_count);
	}
	return *this;
}

template <typename E, class A>
template <typename T, class V>
Array<E,A>& Array<E,A>::operator=(const Array<T,V>& array)
{
	this->destroy();
	size_t a_count = array.count();
	if((this->m_arr_ptr = (E*)A::allocate(a_count)))
	{
		this->m_count = a_count;
		Array<E,A>::Copy<E,T>(this->m_arr_ptr, array.array(), a_count);
	}
	return *this;
}

#if __cplusplus >= 201103L
template <typename E, class A>
Array<E,A>& Array<E,A>::operator=(Array<E,A>&& array)
{
	this->destroy();
	this->m_count = array.m_count;
	this->m_arr_ptr = array.m_arr_ptr;
	array.m_count = 0U;
	array.m_arr_ptr = (E*)0;
	return *this;
}
#endif

template <typename E, class A>
E& Array<E,A>::operator[](size_t index)
{
	return m_arr_ptr[index];
}

template <typename E, class A>
const E& Array<E,A>::operator[](size_t index) const
{
	return m_arr_ptr[index];
}

template <typename E, class A>
template <typename T, class V>
bool Array<E,A>::operator==(const Array<T,V>& array) const
{
	if((void*)this == (void*)&array) return true;
	if(this->m_count != array.count()) return false;
	for(size_t i = 0; i < this->m_count; ++i)
	{
		if(m_arr_ptr[i] != array[i]) return false;
	}
	return true;
}

template <typename E, class A>
template <typename T, class V>
bool Array<E,A>::operator!=(const Array<T,V>& array) const
{
	if((void*)this == (void*)&array || this->m_count != array.count()) return true;
	for(size_t i = 0; i < this->m_count; ++i)
	{
		if(m_arr_ptr[i] != array[i]) return true;
	}
	return false;
}

template <typename E, class A>
void Array<E,A>::destroy()
{
	if(m_arr_ptr)
	{
		A::deallocate((void*)this->m_arr_ptr);
		m_arr_ptr = (E*)0;
		m_count = 0U;
	}
}

template <typename E, class A>
bool Array<E,A>::resize(size_t count)
{
	E* new_ptr;
	if((new_ptr = A::reallocate(this->m_arr_ptr, count, this->m_count)))
	{
		this->m_count = count;
		this->m_arr_ptr = new_ptr;
		return true;
	}
	return false;
}

template <typename E, class A>
template <typename T>
bool Array<E,A>::resize(size_t count, const T& fill_value)
{
	E* new_ptr;
	if((new_ptr = A::reallocate(this->m_arr_ptr, count, this->m_count)))
	{
		size_t min_count = count <= this->m_count ? count : this->m_count;
		for(size_t i = min_count; i < count; ++i)
			new_ptr[i] = fill_value;
		this->m_count = count;
		this->m_arr_ptr = new_ptr;
		return true;
	}
	return false;
}

template <typename E, class A>
bool Array<E,A>::set(E value, size_t count, size_t offset)
{
	if(!this->m_arr_ptr || this->m_count == 0U) return false;
	size_t valid_count = count;
	if(count == -1)
	{
		valid_count = this->m_count;
	}
	else if(count > this->m_count || count + offset > this->m_count)
		return false;
	E* dest = &this->m_arr_ptr[offset];
	for(size_t i = 0; i < valid_count; ++i)
		dest[i] = value;
	return true;
}

template <typename E, class A>
size_t Array<E,A>::count() const
{
	return m_count;
}

template <typename E, class A>
E* Array<E,A>::array()
{
	return m_arr_ptr;
}

template <typename E, class A>
const E* Array<E,A>::array() const
{
	return m_arr_ptr;
}

template <typename E, class A>
template <typename T>
E* Array<E,A>::Copy(E* dest, const T* src, size_t count, size_t offset)
{
	if(!dest || !src) return dest;
	const T* source = &src[offset];
	for(size_t i = 0U; i < count; ++i)
		dest[i] = source[i];
	return dest;
}

} // axl::util::ds
} // axl::util
} // axl
