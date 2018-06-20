#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

namespace cs20 {

template <class Object>
class BST;

template <class Object>
class BSTNode {
public:
	BSTNode( const Object& theElement = Object(), 
			 BSTNode * theLeftSide = nullptr,
			 BSTNode * theRightSide = nullptr,
			 int theSize = 1);
	BSTNode * duplicate() const;

	static int size( BSTNode * t );
	static int height( BSTNode * t );

	// no references to a BSTNode are returned
	// publicly by either BST or BSTIterators
	// these methods are only called by BST and
	// BSTIterators
	const Object& getElement() const;
	BSTNode* getLeftSide() const;
	BSTNode* getRightSide() const;

	std::ostream& printBSTNode ( std::ostream& outs ) const;
	
	friend class BST<Object>;
private:
	Object   element;
	BSTNode* rightSide;
	BSTNode* leftSide;
	int      sz;

	static int max( int a, int b );
};

}
#endif