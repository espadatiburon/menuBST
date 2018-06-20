#ifndef LEVELORDERITERATOR_H
#define LEVELORDERITERATOR_H
#include <iostream>
#include "BST.h"
#include "BSTIterator.h"
#include "Queue.h"

namespace cs20 {

template <class Object>
class LevelOrderIterator : public BSTIterator<Object> {
public:
	LevelOrderIterator( const BST<Object>& theTree );
	virtual ~LevelOrderIterator();

	void advance();
	void first();
	
protected:
	Queue<const BSTNode<Object> *> q;
};

}
#endif