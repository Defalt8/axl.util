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
		Iterator(UniNode<V> *node = (UniNode<V>*)0);
		V& operator*();
		const V& operator*() const;
		V* operator->();
		const V* operator->() const;
		Iterator operator+(size_t offset) const;
		Iterator& operator++();
		Iterator operator++(int);
		bool operator==(const Iterator& iterator) const;
		bool operator!=(const Iterator& iterator) const;
		bool isNull() const;
	private:
		UniNode<V> *node;
	};
public:
	virtual ~UniList();
	UniList();
	UniList(const UniList<V>& node);
public:
	UniList<V>& operator=(const UniList<V>& unilist);
public:
	Iterator begin() const;
	const Iterator end() const;
	Iterator last() const;
	bool isEmpty() const;
	template <typename T = V>
	bool insertFirst(const T& value);
	template <typename T = V>
	bool insertLast(const T& value);
	V removeFirst();
	void removeAll();
private:
	UniNode<V>* m_first;
	UniNode<V>* m_last;
};


} // axl::util::ds
} // axl::util
} // axl

#include "List.inl"
