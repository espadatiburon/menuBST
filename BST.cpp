#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

namespace cs20 {

template <class Object>
BST<Object>::BST() {
	root = nullptr;
}

template <class Object>
BST<Object>::BST( const BST<Object>& rhs ) {
	root = nullptr;
	*this = rhs;
}

template <class Object>
BST<Object>::BST( const Object& rootElement ) {
	root = new BSTNode<Object>( rootElement );
}

template <class Object>
BST<Object>::~BST() {
	makeEmpty();
}

template <class Object>
bool BST<Object>::isEmpty() const {
	return( root == nullptr );
}

template <class Object>
void BST<Object>::makeEmpty() {
	makeEmpty( root );
}

template <class Object>
void BST<Object>::makeEmpty( NodePtr & node ) {
	if (node != nullptr) {
		NodePtr l = node->getLeftSide();
		NodePtr r = node->getRightSide();
		makeEmpty( l );
		makeEmpty( r );
		delete node;
		node = nullptr;
	}
}

template <class Object>
int BST<Object>::size() const {
	return( BSTNode<Object>::size( root ) );
}

template <class Object>
int BST<Object>::height() const {
	return( BSTNode<Object>::height( root ) );
}

template <class Object>
const Object& BST<Object>::findMin() const throw(InvalidTreeArgument) {
	if (root == nullptr)
		throw InvalidTreeArgument();
	return( findMin( root ) );
}

template <class Object>
const Object& BST<Object>::findMax() const throw(InvalidTreeArgument) {
	if (root == nullptr)
		throw InvalidTreeArgument();
	return( findMax( root ) );
}

template <class Object>
const Object& BST<Object>::findMin( NodePtr node ) const {
	while( node->getLeftSide() != nullptr ) {
		node = node->getLeftSide();
	}
	return( node->getElement() );
}

template <class Object>
const Object& BST<Object>::findMax( NodePtr node ) const {
	while( node->getRightSide() != nullptr ) {
		node = node->getRightSide();
	}
	return( node->getElement() );
}

template <class Object>
const Object& BST<Object>::find( const Object& x ) const throw (InvalidTreeArgument) {
	return( find( x, root ) );
}

template <class Object>
const Object& BST<Object>::find( const Object& x, NodePtr node ) const throw (InvalidTreeArgument) {
	if (node == nullptr)
		throw InvalidTreeArgument();
	if (node->getElement() < x) {
		return( find( x, node->getLeftSide() ) );
	}
	if (node->getElement() > x) {
		return( find( x, node->getRightSide() ) );
	}
	return( node->getElement() );
}

template <class Object>
void BST<Object>::insert( const Object& x ) throw (InvalidTreeArgument) {
	insert( x, root );
}

template <class Object>
void BST<Object>::insert( const Object& x, NodePtr& node ) throw (InvalidTreeArgument) {
	if (node == nullptr) {
		node = new BSTNode<Object>( x, nullptr, nullptr );
	}
	else if (x < node->element) {
		insert( x, node->leftSide );
	}
	else if (x > node->element) {
		insert( x, node->rightSide );
	}
	else
		throw InvalidTreeArgument();
}

template <class Object>
void BST<Object>::removeMin() throw (InvalidTreeArgument) {
	removeMin( root );
}

template <class Object>
void BST<Object>::removeMin( NodePtr& node ) throw (InvalidTreeArgument) {
	if (node == nullptr) {
		throw InvalidTreeArgument();
	}
	else if (node->leftSide != nullptr) {
		removeMin( node->leftSide );
	}
	else {
		NodePtr temp = node;
		node = node->rightSide;
		delete temp;
	}
}

template <class Object>
void BST<Object>::remove( const Object& x ) throw (InvalidTreeArgument) {
	remove( x, root ); 
}

template <class Object>
void BST<Object>::remove( const Object& x, NodePtr & node ) throw (InvalidTreeArgument) {
	if (node == nullptr)
		throw InvalidTreeArgument();
	else if (x < node->element) 
		remove( x, node->leftSide );
	else if (x > node->element)
		remove( x, node->rightSide );
	// on the matching node
	else if (node->leftSide != nullptr && node->rightSide != nullptr) {
		// 2 children
		node->element = findMin( node->rightSide );
		removeMin( node->rightSide );
	}
	else {
		// one or no children
		NodePtr temp = node;
		if (node->leftSide != nullptr) {
			node = node->leftSide;
		}
		else {
			node = node->rightSide;
		}
		delete temp;
	}
}

// Deep copy of tree
template <class Object>
const BST<Object>& BST<Object>::operator =( const BST<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != nullptr) 
			root = rhs.root->duplicate();
	}
	return( *this );
}
	
template <class Object>
std::ostream& BST<Object>::printBST( std::ostream& outs ) const {
	if (isEmpty()) 
		outs << "Empty BST";
	else
		root->printBSTNode( outs );
	outs << std::endl;
	return( outs );
}

template <class Object>
BSTNode<Object>* BST<Object>::getRoot() const {
	return( root );
}

template <class Object>
bool BST<Object>::hasSumToLeaf( int value ) throw (InvalidTreeArgument)
{
	int total = 0;
	bool found = false;
	if(root == nullptr)
		throw InvalidTreeArgument();
	if(root->getElement() > value)
	{
		return false;
	}
	else if(root->getElement() == value)
	{
		return true;
	}
	total += root->getElement();
	found = hasSumToLeaf(value, total, root);
	return found;
}

template<class Object>
bool BST<Object>::hasSumToLeaf(int value, int total, BSTNode<Object>* node)
{
	bool found = false;
	if(node != nullptr)
	{
		if((node->getLeftSide() != nullptr)&&((node->getLeftSide()->getElement() + total) == value))
		{
			return true;
		}
		else if((node->getRightSide() != nullptr)&&((node->getRightSide()->getElement() + total) == value))
		{
			return true;
		}
		if((node->getLeftSide() != nullptr)&&(found == false))
		{
			found = hasSumToLeaf(value, node->getLeftSide()->getElement() + total, node->getLeftSide());
		}
		if((node->getRightSide() != nullptr)&&(found == false))
		{
			found = hasSumToLeaf(value, node->getRightSide()->getElement() + total, node->getRightSide());
		}
		if(found)
		{
			return found;
		}
	}
}

}
#endif