#pragma once
#include "../types.hpp"
#include "List.hpp"

namespace axl {
namespace util {
namespace ds {


template <typename KeyType, typename ValueType>
class Map
{
	public:
		class Iterator
		{
			public:
				Iterator(Map<KeyType, ValueType> *map = 0,
					typename const UniList<KeyType>::Iterator& key_it = UniList<KeyType>::Iterator(),
					typename const UniList<ValueType>::Iterator& value_it = UniList<ValueType>::Iterator());
				Iterator(const Iterator& iterator);
				Iterator operator+(size_t offset) const;
				Iterator& operator+=(size_t offset);
				Iterator& operator++();
				Iterator operator++(int);
				bool operator==(const Iterator& iterator) const;
				bool operator!=(const Iterator& iterator) const;
				bool isNull() const;
				bool isNotNull() const;
				Map<KeyType, ValueType>* map() const;
				typename UniList<KeyType>::Iterator& keyIt();
				typename const UniList<KeyType>::Iterator& keyIt() const;
				typename UniList<ValueType>::Iterator& valueIt();
				typename const UniList<ValueType>::Iterator& valueIt() const;
				KeyType& key();
				const KeyType& key() const;
				ValueType& value();
				const ValueType& value() const;
			private:
				Map<KeyType, ValueType> *m_map;
				typename UniList<KeyType>::Iterator m_key_it;
				typename UniList<ValueType>::Iterator m_value_it;
				friend class Map<KeyType, ValueType>;
		};
	public:
		Map();
		Map(const Map& map);
#	if __cplusplus >= 201103L
		Map(const Map&& map);
#	endif
		~Map();
	public:
		Map& operator=(const Map& map);
#	if __cplusplus >= 201103L
		Map& operator=(const Map&& map);
#	endif
		ValueType& operator[](const KeyType& key);
		const ValueType& operator[](const KeyType& key) const;
	public:
		size_t count() const;
		Iterator first() const;
		Iterator end() const;
		Iterator last() const;
		Iterator positionOf(const KeyType& key) const;
		Iterator at(size_t index) const;
		bool isEmpty() const;
		bool add(const KeyType& key, const ValueType& value);
		bool remove(const KeyType& key);
		bool removeAt(const Iterator& it);
		void removeAll();
		bool set(const KeyType& key, const ValueType& value);
		bool get(const KeyType& key, ValueType*const out_value) const;
	protected:
		UniList<KeyType> map_keys;
		UniList<ValueType> map_values;
};

} // axl.util.ds
} // axl.util
} // axl

#include "Map.inl"
