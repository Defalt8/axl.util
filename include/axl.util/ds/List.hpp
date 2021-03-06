#pragma once
#include "Array.hpp"
#include "Node.hpp"

namespace axl {
namespace util {
namespace ds {

// Unidirectional list
template <typename V>
class UniList
{
public:
	class Iterator
	{
	public:
		Iterator(UniList<V> *list = (UniList<V>*)0, UniNode<V> *node = (UniNode<V>*)0);
		Iterator(const Iterator& iterator);
		V& operator*();
		const V& operator*() const;
		V* operator->();
		const V* operator->() const;
		Iterator operator+(size_t offset) const;
		Iterator& operator+=(size_t offset);
		Iterator& operator++();
		Iterator operator++(int);
		bool operator==(const Iterator& iterator) const;
		bool operator!=(const Iterator& iterator) const;
		bool isNull() const;
		bool isNotNull() const;
		UniList<V>* list() const;
		V& value(); 
		const V& value() const; 
	private:
		UniList<V> *m_list;
		UniNode<V> *m_node;
		friend class UniList<V>;
	};
public:
	virtual ~UniList();
	UniList();
	UniList(const UniList<V>& unilist);
	UniList(UniList<V>&& unilist);
public:
	UniList<V>& operator=(const UniList<V>& unilist);
	UniList<V>& operator=(UniList<V>&& unilist);
public:
	size_t count() const;
	Iterator first() const;
	Iterator end() const;
	Iterator last() const;
	Iterator positionOf(const V& value) const;
	Iterator at(size_t index) const;
	bool isEmpty() const;
	template <typename T = V>
	bool insertFirst(const T& value);
	template <typename T = V>
	bool insertLast(const T& value);
	template <typename T = V>
	bool insertAfter(const T& value, const Iterator& position = Iterator((UniList<V>*)0, (UniNode<V>*)0));
	template <typename T = V>
	bool insertAfterValue(const T& value, const V& after_value);
	V removeFirst();
	bool remove(const V& value);
	bool removeAt(const UniList<V>::Iterator& iterator);
	void removeAll();
private:
	UniNode<V>* m_first;
	UniNode<V>* m_last;
	size_t m_count;
};


} // axl::util::ds
} // axl::util
} // axl

#include "List.inl"
