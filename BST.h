#ifndef BST_H
#define BST_H
// pragma for Visual Studio's lack of support for checked exceptions
#pragma warning( disable: 4290)
#include <iostream>
#include <cstddef>
#include "BSTNode.h"
#include "InvalidTreeArgument.h"

namespace cs20 {

template <class Object>
class BSTIterator;

template <class Object>
class BST {
public:
	BST();
	BST( const Object& rootElement );
	BST( const BST& rhs );
	~BST();

	bool isEmpty() const;
	void makeEmpty();
	int size() const;
	int height() const;
	const Object& find( const Object& x ) const throw (InvalidTreeArgument);
	const Object& findMin() const throw (InvalidTreeArgument);
	const Object& findMax() const throw (InvalidTreeArgument);
	void insert( const Object& x ) throw (InvalidTreeArgument);
	void remove( const Object& x ) throw (InvalidTreeArgument);
	void removeMin() throw (InvalidTreeArgument);
	bool hasSumToLeaf( int value ) throw (InvalidTreeArgument);
	bool hasSumToLeaf(int value, int total, BSTNode<Object>* node);
	
	const BST& operator =( const BST& rhs );
	std::ostream& printBST( std::ostream& outs ) const;

	BSTNode<Object>* getRoot() const;
private:
	typedef BSTNode<Object>* NodePtr;
	NodePtr root;
	void makeEmpty( NodePtr &t );
	friend class BSTIterator<Object>;

	const Object& find( const Object& x, NodePtr node ) const throw (InvalidTreeArgument);
	const Object& findMin( NodePtr node ) const;
	const Object& findMax( NodePtr node ) const;
	void insert( const Object& x, NodePtr & node ) throw (InvalidTreeArgument);
	void remove( const Object& x, NodePtr & node ) throw (InvalidTreeArgument);
	void removeMin( NodePtr & node ) throw (InvalidTreeArgument);

};

}
#endif