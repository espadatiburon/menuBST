#ifndef BSTITERATOR_H
#define BSTITERATOR_H
#include <iostream>
#include "BSTNode.h"
#include "BST.h"
#include "BadIterator.h"

namespace cs20 {

template <class Object>
class BSTIterator {
public:
	BSTIterator( const BST<Object>& theTree );
	virtual ~BSTIterator();

	bool isValid() const;
	virtual void advance() = 0;
	virtual void first() = 0;
	const Object& retrieve() const;
	
protected:
	const BSTNode<Object> * current;
	const BSTNode<Object> * root;

};

}
#endif