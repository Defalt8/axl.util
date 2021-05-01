#include "List.hpp"

namespace axl {
namespace util {
namespace ds {

//
// UniList::Iterator
//

template <typename V>
UniList<V>::Iterator::Iterator(UniList<V> *p_list, UniNode<V> *p_node) :
	m_list(p_list),
	m_node(p_node)
{}

template <typename V>
UniList<V>::Iterator::Iterator(const UniList<V>::Iterator& iterator) :
	m_list(iterator.m_list),
	m_node(iterator.m_node)
{}

template <typename V>
V& UniList<V>::Iterator::operator*()
{
	if(!this->m_node) throw "Null pointer";
	return this->m_node->value;
}

template <typename V>
const V& UniList<V>::Iterator::operator*() const
{
	if(!this->m_node) throw "Null pointer";
	return this->m_node->value;
}

template <typename V>
V* UniList<V>::Iterator::operator->()
{
	if(!this->m_node) throw "Null pointer";
	return &this->m_node->value;
}

template <typename V>
const V* UniList<V>::Iterator::operator->() const
{
	if(!this->m_node) throw "Null pointer";
	return &this->m_node->value;
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::Iterator::operator+(size_t offset) const
{
	UniList<V>::Iterator iterator(this->m_list, this->m_node);
	size_t counter = 0;
	while(iterator.m_node && ++counter <= offset)
	{
		iterator.m_node = iterator.m_node->next;
	}
	return iterator;
}

template <typename V>
typename UniList<V>::Iterator& UniList<V>::Iterator::operator+=(size_t offset)
{
	size_t counter = 0;
	while(this->m_node && ++counter <= offset)
	{
		this->m_node = this->m_node->next;
	}
	return *this;
}


template <typename V>
typename UniList<V>::Iterator& UniList<V>::Iterator::operator++()
{
	if(this->m_node)
		this->m_node = this->m_node->next;
	return *this;
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::Iterator::operator++(int)
{
	UniList<V>::Iterator iterator(this->m_list, this->m_node);
	if(this->m_node)
		this->m_node = this->m_node->next;
	return iterator;
}

template <typename V>
bool UniList<V>::Iterator::operator==(const Iterator& iterator) const
{
	return this->m_list == iterator.m_list && this->m_node == iterator.m_node;
}

template <typename V>
bool UniList<V>::Iterator::operator!=(const Iterator& iterator) const
{
	return this->m_node != iterator.m_node;
}

template <typename V>
bool UniList<V>::Iterator::isNull() const
{
	return (UniNode<V>*)0 == this->m_node;
}

template <typename V>
bool UniList<V>::Iterator::isNotNull() const
{
	return (UniNode<V>*)0 != this->m_node;
}

template <typename V>
UniList<V>* UniList<V>::Iterator::list() const
{
	return this->m_list;
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
	m_last(unilist.m_last)
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
	return UniList<V>::Iterator((UniList<V>*)this, this->m_first);
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::end() const
{
	return UniList<V>::Iterator((UniList<V>*)0, (UniNode<V>*)0);
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::last() const
{
	return UniList<V>::Iterator((UniList<V>*)this, this->m_last);
}

template <typename V>
typename UniList<V>::Iterator UniList<V>::positionOf(const V& value) const
{
	Iterator it((UniList<V>*)this, this->m_first);
	for(; it.m_node != (UniNode<V>*)0; ++it)
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
	UniNode<V>* new_node = new UniNode<V>(value, position.m_node->next);
	if(!new_node) return false;
	position.m_node->next = new_node;
	++this->m_count;
	return true;
}

template <typename V>
template <typename T>
bool UniList<V>::insertAfterValue(const T& value, const V& after_value)
{
	for(Iterator it((UniList<V>*)this, this->m_first); it.m_node != (UniNode<V>*)0; ++it)
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
bool UniList<V>::remove(const V& value)
{
	if(this->m_first)
	{
		UniNode<V>* first = this->m_first;
		if(value == first->value)
		{
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
			return true;
		}
		else
		{
			for(UniNode<V>* it = first->next, *prev = (UniNode<V>*)first; it != (UniNode<V>*)0; prev = it, it = it->next)
			{
				if(it && it->value == value)
				{
					if(prev) prev->next = it->next;
					delete it;
					if(this->m_count <= 0) throw "List element count is off.";
					--this->m_count;
					return true;
				}
			}
		}
	}
	return false;
}

template <typename V>
bool UniList<V>::removeAt(const UniList<V>::Iterator& iterator)
{
	if(this->m_first && iterator.m_list == (UniList<V>*)this)
	{
		UniNode<V>* first = this->m_first;
		if((*iterator) == first->value)
		{
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
			return true;
		}
		else
		{
			for(UniNode<V>* it = first->next, *prev = (UniNode<V>*)first; it != (UniNode<V>*)0; prev = it, it = it->next)
			{
				if(it && it->value == (*iterator))
				{
					if(prev) prev->next = it->next;
					delete it;
					if(this->m_count <= 0) throw "List element count is off.";
					--this->m_count;
					return true;
				}
			}
		}
	}
	return false;
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
