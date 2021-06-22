#include "Map.hpp"

namespace axl {
namespace util {
namespace ds {

//
// Map::Iterator
//

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Iterator::Iterator(Map<KeyType, ValueType> *_map,
	const typename UniList<KeyType>::Iterator& _key_it,
	const typename UniList<ValueType>::Iterator& _value_it) :
	m_map(_map),
	m_key_it(_key_it),
	m_value_it(_value_it)
{}
template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Iterator::Iterator(const Iterator& iterator) :
	m_map(iterator.m_map),
	m_key_it(iterator.m_key_it),
	m_value_it(iterator.m_value_it)
{}
template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::Iterator::operator+(size_t offset) const
{
	return Map<KeyType,ValueType>::Iterator(m_map, (m_key_it+offset), (m_value_it+offset));
}
template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator& Map<KeyType,ValueType>::Iterator::operator+=(size_t offset)
{
	m_key_it += offset;
	m_value_it += offset;
	return *this;
}
template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator& Map<KeyType,ValueType>::Iterator::operator++()
{
	++m_key_it;
	++m_value_it;
	return *this;
}
template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::Iterator::operator++(int)
{
	return Map<KeyType,ValueType>::Iterator(m_map, m_key_it++, m_value_it++);
}
template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::Iterator::operator==(const Map<KeyType,ValueType>::Iterator& iterator) const
{
	return m_map == iterator.m_map &&
		m_key_it == iterator.m_key_it &&
		m_value_it == iterator.m_value_it;
}
template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::Iterator::operator!=(const Map<KeyType,ValueType>::Iterator& iterator) const
{
	return m_map != iterator.m_map ||
		m_key_it != iterator.m_key_it ||
		m_value_it != iterator.m_value_it;
}
template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::Iterator::isNull() const
{
	return !m_map || m_key_it.isNull() || m_value_it.isNull();
}
template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::Iterator::isNotNull() const
{
	return m_map && m_key_it.isNotNull() && m_value_it.isNotNull();
}
template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>* Map<KeyType, ValueType>::Iterator::map() const
{
	return m_map;
}
template <typename KeyType, typename ValueType>
typename UniList<KeyType>::Iterator& Map<KeyType, ValueType>::Iterator::keyIt()
{
	return m_key_it;
}
template <typename KeyType, typename ValueType>
const typename UniList<KeyType>::Iterator& Map<KeyType, ValueType>::Iterator::keyIt() const
{
	return m_key_it;
}
template <typename KeyType, typename ValueType>
typename UniList<ValueType>::Iterator& Map<KeyType, ValueType>::Iterator::valueIt()
{
	return m_value_it;
}
template <typename KeyType, typename ValueType>
const typename UniList<ValueType>::Iterator& Map<KeyType, ValueType>::Iterator::valueIt() const
{
	return m_value_it;
}
template <typename KeyType, typename ValueType>
KeyType& Map<KeyType, ValueType>::Iterator::key()
{
	return m_key_it.value();
}
template <typename KeyType, typename ValueType>
const KeyType& Map<KeyType, ValueType>::Iterator::key() const
{
	return m_key_it.value();
}
template <typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::Iterator::value()
{
	return m_value_it.value();
}
template <typename KeyType, typename ValueType>
const ValueType& Map<KeyType, ValueType>::Iterator::value() const
{
	return m_value_it.value();
}

//
// Map
//



template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map() :
	map_keys(),
	map_values()
{}

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map(const Map<KeyType,ValueType>& map) :
	map_keys(map.map_keys),
	map_values(map.map_values)
{}

#if __cplusplus >= 201103L

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::Map(const Map<KeyType,ValueType>&& map) :
	map_keys(map.map_keys),
	map_values(map.map_values)
{}

#endif

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>::~Map()
{}


template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>& Map<KeyType,ValueType>::operator=(const Map<KeyType,ValueType>& map)
{
	map_keys = map.map_keys;
	map_values = map.map_values;
	return *this;
}

#if __cplusplus >= 201103L

template <typename KeyType, typename ValueType>
Map<KeyType,ValueType>& Map<KeyType,ValueType>::operator=(const Map<KeyType,ValueType>&& map)
{
	map_keys = map.map_keys;
	map_values = map.map_values;
	return *this;
}

#endif

template <typename KeyType, typename ValueType>
ValueType& Map<KeyType,ValueType>::operator[](const KeyType& key)
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
			return value_it.value();
	}
	return map_values.end().value();
}

template <typename KeyType, typename ValueType>
const ValueType& Map<KeyType,ValueType>::operator[](const KeyType& key) const
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
			return value_it.value();
	}
	return map_values.end().value();
}


template <typename KeyType, typename ValueType>
size_t Map<KeyType,ValueType>::count() const
{
	return map_keys.count();
}

template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::first() const
{
	return Iterator((Map<KeyType,ValueType>*)this, map_keys.first(), map_values.first());
}

template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::end() const
{
	return Iterator((Map<KeyType,ValueType>*)this, map_keys.end(), map_values.end());
}

template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::last() const
{
	return Iterator((Map<KeyType,ValueType>*)this, map_keys.last(), map_values.last());
}

template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::positionOf(const KeyType& key) const
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
			return Iterator((Map<KeyType,ValueType>*)this, key_it, value_it);
	}
	return Iterator((Map<KeyType,ValueType>*)this, typename UniList<KeyType>::Iterator(), typename UniList<ValueType>::Iterator());
}

template <typename KeyType, typename ValueType>
typename Map<KeyType,ValueType>::Iterator Map<KeyType,ValueType>::at(size_t index) const
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it, --index)
	{
		if(index == 0)
			return Iterator((Map<KeyType,ValueType>*)this, key_it, value_it);
	}
	return Iterator((Map<KeyType,ValueType>*)this, typename UniList<KeyType>::Iterator(), typename UniList<ValueType>::Iterator());
}

template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::isEmpty() const
{
	return map_keys.isEmpty() || map_values.isEmpty();
}

template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::add(const KeyType& key, const ValueType& value)
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
			return false;
	}
	return map_keys.insertLast(key) && map_values.insertLast(value);
}

template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::remove(const KeyType& key)
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
			return map_keys.removeAt(key_it) && map_values.removeAt(value_it);
	}
	return false;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::removeAt(const Iterator& it)
{
	return map_keys.removeAt(it.m_key_it) && map_values.removeAt(it.m_value_it);
}

template <typename KeyType, typename ValueType>
void Map<KeyType,ValueType>::removeAll()
{
	map_keys.removeAll();
	map_values.removeAll();
}

template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::set(const KeyType& key, const ValueType& value)
{
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
		{
			value_it.value() = value;
			return true;
		}
	}
	return false;
}

template <typename KeyType, typename ValueType>
bool Map<KeyType,ValueType>::get(const KeyType& key, ValueType*const out_value) const
{
	if(!out_value) return false;
	typename UniList<ValueType>::Iterator value_it = map_values.first();
	for(typename UniList<KeyType>::Iterator key_it = map_keys.first(); key_it.isNotNull() && value_it.isNotNull(); ++key_it, ++value_it)
	{
		if(key_it.value() == key)
		{
			*out_value = value_it.value();
			return true;
		}
	}
	return false;
}

template <typename KeyType, typename ValueType>
UniList<KeyType>& Map<KeyType,ValueType>::keys()
{
	return map_keys;
}
template <typename KeyType, typename ValueType>
const UniList<KeyType>& Map<KeyType,ValueType>::keys() const
{
	return map_keys;
}
template <typename KeyType, typename ValueType>
UniList<ValueType>& Map<KeyType,ValueType>::values()
{
	return map_values;
}
template <typename KeyType, typename ValueType>
const UniList<ValueType>& Map<KeyType,ValueType>::values() const
{
	return map_values;
}


} // axl.util.ds
} // axl.util
} // axl
