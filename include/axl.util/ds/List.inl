#include "List.hpp"

namespace axl {
namespace util {
namespace ds {

//
// UniList::Iterator
//

template <typename V>
UniList<V>::Iterator::Iterator(UniNode<V> *p_node) :
	node(p_node)
{}

template <typename V>
V& UniList<V>::Iterator::operator*()
{
	if(!this->node) throw "Null pointer";
	return this->node->value;
}

template <typename V>
const V& UniList<V>::Iterator::operator*() const
{
	if(!this->node) throw "Null pointer";
	return this->node->value;
}

template <typename V>
V* UniList<V>::Iterator::operator->()
{
	if(!this->node) throw "Null pointer";
	return &this->node->value;
}

template <typename V>
const V* UniList<V>::Iterator::operator->() const
{
	if(!this->node) throw "Null pointer";
	return &this->node->value;
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::Iterator::operator+(size_t offset) const
{
	size_t counter = 0;
	while(this->node && ++counter <= offset)
	{
		this->node = this->node->next;
	}
	return *this;
}


template <typename V>
typename UniList<V>::Iterator& UniList<V>::Iterator::operator++()
{
	if(this->node)
		this->node = this->node->next;
	return *this;
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::Iterator::operator++(int)
{
	UniList<V>::Iterator iterator(this->node);
	if(this->node)
		this->node = this->node->next;
	return iterator;
}

template <typename V>
bool UniList<V>::Iterator::operator==(const Iterator& iterator) const
{
	return this->node == iterator.node;
}

template <typename V>
bool UniList<V>::Iterator::operator!=(const Iterator& iterator) const
{
	return this->node != iterator.node;
}

template <typename V>
bool UniList<V>::Iterator::isNull() const
{
	return (UniNode<V>*)0 == this->node;
}

//
// UniList
//

template <typename V>
UniList<V>::~UniList()
{
	removeAll();
}

template <typename V>
UniList<V>::UniList() :
	m_count(),
	m_first(),
	m_last()
{}

template <typename V>
UniList<V>::UniList(const UniList<V>& unilist) :
	m_first(unilist.m_first),
	m_first(unilist.m_last)
{}

template <typename V>
UniList<V>& UniList<V>::operator=(const UniList<V>& unilist)
{
	this->m_first = unilist.m_first;
	this->m_last = unilist.m_last;
	return *this;
}

template <typename V>
size_t UniList<V>::count() const
{
	return this->m_count;
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::first() const
{
	return UniList<V>::Iterator(this->m_first);
}

template <typename V>
typename const UniList<V>::Iterator UniList<V>::end() const
{
	return UniList<V>::Iterator((UniNode<V>*)0);
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::last() const
{
	return UniList<V>::Iterator(this->m_last);
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::positionOf(const V& value) const
{
	Iterator it = this->m_first;
	for(; it != (UniNode<V>*)0; ++it)
	{
		if(*it == value) break;
	}
	return it;
}

template <typename V>
bool UniList<V>::isEmpty() const
{
	return (UniNode<V>*)0 == this->m_first;
}

template <typename V>
template <typename T>
bool UniList<V>::insertFirst(const T& value)
{
	UniNode<V> *new_node = new UniNode<V>(value);
	if(!new_node) return false;
	new_node->next = this->m_first;
	if(!this->m_first)
	{
		this->m_first = this->m_last = new_node;
	}
	else
	{
		this->m_first = new_node;
	}
	++this->m_count;
	return true;
}

template <typename V>
template <typename T>
bool UniList<V>::insertLast(const T& value)
{
	UniNode<V> *new_node = new UniNode<V>(value);
	if(!new_node) return false;
	if(!this->m_first)
	{
		this->m_first = this->m_last = new_node;
	}
	else if(this->m_first == this->m_last)
	{
		this->m_last = new_node;
		this->m_first->next = this->m_last;
	}
	else
	{
		this->m_last->next = new_node;
		this->m_last = new_node;
	}
	++this->m_count;
	return true;
}

template <typename V>
template <typename T>
bool UniList<V>::insertAfter(const T& value, const UniList<V>::Iterator& position)
{
	if(position.isNull()) return this->insertFirst(value);
	UniNode<V>* new_node = new UniNode<V>(value, position.node->next);
	if(!new_node) return false;
	position.node->next = new_node;
	++this->m_count;
	return true;
}

template <typename V>
template <typename T>
bool UniList<V>::insertAfterValue(const T& value, const V& after_value)
{
	for(Iterator it = this->m_first; it != (UniNode<V>*)0; ++it)
	{
		if(*it == after_value)
			return this->insertAfter(value, it);
	}
	return false;
}

template <typename V>
V UniList<V>::removeFirst()
{
	V value;
	if(this->m_first)
	{
		UniNode<V>* first = this->m_first;
		value = this->m_first->value;
		if(this->m_first == this->m_last)
		{
			this->m_first = this->m_last = (UniNode<V>*)0;
		}
		else
		{
			this->m_first = first->next;
		}
		delete first;
		if(this->m_count <= 0) throw "List element count is off.";
		--this->m_count;
	}
	else
	{
		value = V();
	}
	return value;
}

template <typename V>
void UniList<V>::removeAll()
{
	if(this->m_first)
	{
		UniNode<V> *it, *next;
		for(it = this->m_first; it != (UniNode<V>*)0; it = next)
		{
			next = it->next;
			delete it;
		}
	}
	this->m_count = 0;
	this->m_first = this->m_last = (UniNode<V>*)0;
}

} // axl::util::ds
} // axl::util
} // axl
