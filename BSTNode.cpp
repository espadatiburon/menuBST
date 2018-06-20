#ifndef BSTNODE_CPP
#define BSTNODE_CPP

#include "BSTNode.h"

namespace cs20 {

template <class Object>
BSTNode<Object>::BSTNode( const Object& theElement,
								  BSTNode<Object> * theLeftSide,
								  BSTNode<Object> * theRightSide,
								  int theSize) {
	element = theElement;
	rightSide = theRightSide;
	leftSide = theLeftSide;
	sz = theSize;
}

template <class Object>
int BSTNode<Object>::size( BSTNode<Object> * node ) {
	if (node == nullptr )
		return( 0 );
	else
		return( 1 + size( node->rightSide ) + size( node->leftSide ) );
}

template <class Object>
int BSTNode<Object>::height( BSTNode<Object> * node ) {
	if (node == nullptr )
		return( -1 );
	else
		return( 1 + max( height( node->leftSide ), height( node->rightSide ) ) );
}

template <class Object>
BSTNode<Object> * BSTNode<Object>::duplicate( ) const {
	BSTNode<Object> * newNode = new BSTNode<Object>( element );
	if (rightSide != nullptr) {
		newNode->rightSide = rightSide->duplicate();
	}
	if (leftSide != nullptr) {
		newNode->leftSide = leftSide->duplicate();
	}
	newNode->sz = sz;
	return( newNode );
}

template <class Object>
std::ostream& BSTNode<Object>::printBSTNode( std::ostream& outs ) const {
	Object o = element;
	outs << o << " ";
	if (leftSide != nullptr)
		leftSide->printBSTNode( outs );
	else
		outs << "LSNULLPTR ";
	if (rightSide != nullptr)
		rightSide->printBSTNode( outs );
	else
		outs << "RSNULLPTR ";
	outs << std::endl;
	return( outs );
}

template <class Object>
int BSTNode<Object>::max( int a, int b ) {
	int result = a;
	if (b > a)
		result = b;
	return( result );
}

template <class Object>
const Object& BSTNode<Object>::getElement() const {
	return( element );
}

template <class Object>
BSTNode<Object>* BSTNode<Object>::getLeftSide() const {
	return( leftSide );
}

template <class Object>
BSTNode<Object>* BSTNode<Object>::getRightSide() const {
	return( rightSide );
}

}
#endif