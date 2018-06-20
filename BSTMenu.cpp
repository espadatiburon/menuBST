// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "BadIterator.h"
#include "InvalidTreeArgument.h"
#include "LevelOrderIterator.h"
#include "LevelOrderIterator.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "QueueNode.h"
#include "QueueNode.cpp"
#include "BST.h"
#include "BST.cpp"
#include "BSTIterator.h"
#include "BSTIterator.cpp"
#include "BSTNode.h"
#include "BSTNode.cpp"

using namespace std;
using namespace cs20;

enum CHOICE {MAKEEMPTY, ISEMPTY, SIZE, HEIGHT, QUIT, PRINT, PRINTNODE, LEVELORDER, INSERT, REMOVE, SETROOT, REMOVEMIN, FINDMIN, FINDMAX, FIND, HASSUM };

CHOICE menu();
void printTree( const BST<int>& t );

int main(int argc, char* argv[]) {
	int value;
	BST<int> tree;
	BSTNode<int> * node = nullptr;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			tree.makeEmpty();
			node = nullptr;
			break;
		case ISEMPTY:
			if (tree.isEmpty()) {
				cout << "tree is empty" << endl;
			}
			else {
			cout << "tree is not empty" << endl;
			}
			break;
		case SIZE:
			if (node == nullptr) {
				cout << "You silly... the current node is NULL!" << endl;
			}
			else {
				cout << "size of current node=" << BSTNode<int>::size( node ) << endl;
			}
			break;
		case HEIGHT:
			if (node == nullptr) {
				cout << "You silly... the current node is NULL!" << endl;
			}
			else {
				cout << "height of current node=" << BSTNode<int>::height( node ) << endl;
			}
			break;
		case PRINT:
			printTree( tree );
			break;
		case PRINTNODE:
			if (node == nullptr) {
				cout << "You silly... the current node is NULL!" << endl;
			}
			else {
				value = node->getElement();
				cout << "value of current node=" << value << endl;
			}
			break;
		case INSERT:
			try {
				cout << "Enter a value to insert: ";
				cin  >> value;
				tree.insert( value );
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case REMOVE:
			try {
				cout << "Enter a value to remove: ";
				cin  >> value;
				tree.remove( value );
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case SETROOT:
			cout << "Enter root value: ";
			cin  >> value;
			// not sure this is too clever...
			tree = BST<int>( value );
			node = tree.getRoot();
			break;
		case LEVELORDER:
			try {
				LevelOrderIterator<int> iter( tree );
				iter.first();
				while( iter.isValid() ) {
					value = iter.retrieve();
					cout << value << " ";
					iter.advance();
				}
				cout << endl;
			}
			catch( BadIterator bi ) {
				cout << "badIterator exception caught!" << endl;
			}
			break;
		case FIND:
			try {
				cout << "Enter a value to find: ";
				cin  >> value;
				tree.find( value );
				cout << value << " was found somewhere..." << endl;
			} catch( InvalidTreeArgument ita ) {
				cout << "You silly... that wasn't found in the tree!" << endl;
			}
			break;
		case FINDMIN:
			try {
				value = tree.findMin();
				cout << value << " is the minimum data element in the tree" << endl;
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case FINDMAX:
			try {
				value = tree.findMax();
				cout << value << " is the maximum data element in the tree" << endl;
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case REMOVEMIN:
			try {
				tree.removeMin();
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case HASSUM:
			try {
				cout << "Please insert the sum you want to look for: ";
				cin >> value;
				if(tree.hasSumToLeaf(value))
				{
					cout << "The sum can been found!" << endl;
				}
				else
				{
					cout << "That sum cannot be found!" << endl;
				}
			} catch (InvalidTreeArgument ita) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
        case QUIT:
            break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

void printTree( const BST<int> & t ) {
	t.printBST( cout );
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty si(Z)e (H)eight setRoo(T) (P)rint printN(O)de le(V)elOrder (I)nsert (R)emove RemoveMin(Y) FindMi(N) FindMa(X) (F)ind H(a)sSum (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'Z':
	case 'z':
		result = SIZE;
		break;
	case 'H':
	case 'h':
		result = HEIGHT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'O':
	case 'o':
		result = PRINTNODE;
		break;
	case 'T':
	case 't':
		result = SETROOT;
		break;
	case 'V':
	case 'v':
		result = LEVELORDER;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
	case 'R':
	case 'r':
		result = REMOVE;
		break;
	case 'Y':
	case 'y':
		result = REMOVEMIN;
		break;
	case 'N':
	case 'n':
		result = FINDMIN;
		break;
	case 'X':
	case 'x':
		result = FINDMAX;
		break;
	case 'F':
	case 'f':
		result = FIND;
		break;
	case 'A':
	case 'a':
		result = HASSUM;
		break;
	}

	return( result );
}
