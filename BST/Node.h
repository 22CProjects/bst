/* Specification and implementation of Node ADT */
#ifndef _NODE
#define _NODE

template <class DataType, class KeyType>
class Node
{
protected:
	KeyType key;
	DataType data;	// To hold data
	Node *nextNode;	// To point to the next node in the list

public:
	// Default constructor
	Node() : nextNode(0) {}		// Initialize nextNode pointer to nullptr

	// Overloaded constructor: Initialize data, and nextNode to parameter d and n
	Node(DataType d, Node* n) : key(d), data(d), nextNode(n) {}
	//key option
	Node(KeyType k, DataType d, Node* n) : key(k), data(d), nextNode(n) {}

	// Destructor
	~Node(){}

	// Mutator
	void     set_next(Node* ptr) { nextNode = ptr; }

	// Accessors
	KeyType  get_key() const { return key; }
	DataType get_data() const { return data; }
	Node*    get_next() const { return nextNode; }
	
};
#endif // !_NODE
