#pragma once
#include "../allocators.hpp"
#include "Array.hpp"

namespace axl {
namespace util {
namespace ds {

// Unidirectional node
template <typename V>
class UniNode
{
public:
	virtual ~UniNode();
	template <typename T = V>
	UniNode(T value = T(), UniNode<V>* next = (UniNode<V>*)0);
	UniNode(const UniNode<V>& node);
public:
	UniNode<V>& operator=(const V& value);
	UniNode<V>& operator=(const UniNode<V>& node);
public:
	V value;
	UniNode<V>* next;
};

// Bidirectional node
template <typename V>
class BiNode
{
public:
	virtual ~BiNode();
	template <typename T = V>
	BiNode(T value = T(), BiNode<V>* previous = (BiNode<V>*)0, BiNode<V>* next = (BiNode<V>*)0);
	BiNode(const BiNode<V>& node);
public:
	BiNode<V>& operator=(const V& value);
	BiNode<V>& operator=(const BiNode<V>& node);
public:
	V value;
	BiNode<V>* previous;
	BiNode<V>* next;
};

// Polydirectional node
template <typename V>
class PolyNode
{
public:
	virtual ~PolyNode();
	template <typename T = V>
	PolyNode(T value = T(), const Array<PolyNode<V>*,Allocators::Calloc<V>>& children = Array<PolyNode<V>*,Allocators::Calloc<V>>(0));
	PolyNode(const PolyNode<V>& node);
public:
	PolyNode<V>& operator=(const V& value);
	PolyNode<V>& operator=(const PolyNode<V>& node);
public:
	V value;
	Array<PolyNode<V>*,Allocators::Calloc<V>> children;
};

} // axl::util::ds
} // axl::util
} // axl

#include "Node.inl"
