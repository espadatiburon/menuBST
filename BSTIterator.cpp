#ifndef BSTITERATOR_CPP
#define BSTITERATOR_CPP

#include "BSTIterator.h"

namespace cs20 {

template <class Object>
BSTIterator<Object>::BSTIterator( const BST<Object> & theTree ) : root( theTree.root ) , current( nullptr ) {
//	all assignments performed above
}

template <class Object>
BSTIterator<Object>::~BSTIterator() {

}

template <class Object>
bool BSTIterator<Object>::isValid( ) const {
	return( (current != nullptr) );
}


template <class Object>
const Object& BSTIterator<Object>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}

}
#endif