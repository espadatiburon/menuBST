#ifndef QUEUENODE_CPP
#define QUEUENODE_CPP

#include "QueueNode.h"

namespace cs20 {

template <class Object>
QueueNode<Object>::QueueNode( const Object& theElement,
								      QueueNode<Object> * node ) {
	element = theElement;
	next = node;
}

template <class Object>
const Object& QueueNode<Object>::getElement() const {
	return( element );
}

template <class Object>
QueueNode<Object>* QueueNode<Object>::getNext() const {
	return( next );
}

template <class Object>
void QueueNode<Object>::setNext( QueueNode<Object> * node ) {
	next = node;
}

}

#endif