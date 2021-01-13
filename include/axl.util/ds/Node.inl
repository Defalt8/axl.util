#include "Node.hpp"

namespace axl {
namespace util {
namespace ds {

//
// UniNode
//

template <typename V>
UniNode<V>::~UniNode()
{}

template <typename V>
template <typename T>
UniNode<V>::UniNode(T p_value, UniNode<V>* p_next) :
	value(p_value),
	next(p_next)
{}

template <typename V>
UniNode<V>::UniNode(const UniNode<V>& node) :
	value(node.value),
	next(node.next)
{}

template <typename V>
UniNode<V>& UniNode<V>::operator=(const V& p_value)
{
	value = p_value;
	return *this;
}

template <typename V>
UniNode<V>& UniNode<V>::operator=(const UniNode<V>& node)
{
	value = node.value;
	next = node.next;
	return *this;
}

//
// BiNode
//

template <typename V>
BiNode<V>::~BiNode()
{}

template <typename V>
template <typename T>
BiNode<V>::BiNode(T p_value, BiNode<V>* p_previous, BiNode<V>* p_next) :
	value(p_value),
	previous(p_previous),
	next(p_next)
{}

template <typename V>
BiNode<V>::BiNode(const BiNode<V>& node) :
	value(node.value),
	previous(node.previous),
	next(node.next)
{}

template <typename V>
BiNode<V>& BiNode<V>::operator=(const V& p_value)
{
	value = p_value;
	return *this;
}

template <typename V>
BiNode<V>& BiNode<V>::operator=(const BiNode<V>& node)
{
	value = node.value;
	next = node.next;
	return *this;
}

//
// PolyNode
//

template <typename V>
PolyNode<V>::~PolyNode()
{}

template <typename V>
template <typename T>
PolyNode<V>::PolyNode(T p_value, const Array<PolyNode<V>*,Allocators::Calloc<V>>& p_children) :
	value(p_value),
	children(p_children)
{}

template <typename V>
PolyNode<V>::PolyNode(const PolyNode<V>& node) :
	value(node.value),
	children(node.children)
{}

template <typename V>
PolyNode<V>& PolyNode<V>::operator=(const V& p_value)
{
	value = p_value;
	return *this;
}

template <typename V>
PolyNode<V>& PolyNode<V>::operator=(const PolyNode<V>& node)
{
	value = node.value;
	children = node.children;
	return *this;
}

} // axl::util::ds
} // axl::util
} // axl
