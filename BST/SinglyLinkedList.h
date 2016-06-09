/* Specification and implementation of SinglyLinkedList*/
#pragma once

#include "Node.h"
#include "Head.h"
#include <iostream>
using namespace std;

template <class DataType, class KeyType>
class SinglyLinkedList
{
protected:
	Head<DataType, KeyType> headNode;

public:
	/* DEFAULT CONSTRUCTOR */
	SinglyLinkedList();
	
	/* Deconstructor
		-deallocates memory of the nodes in the list
	*/
	~SinglyLinkedList();

	/* Definition of addTop
		- It adds newData to the front of thelist
		- Parameter: a DataType variable to be added
		- Return: none
	*/
	void addTop(KeyType newKey, DataType newData);

	/* Definition of addEnd
	- It adds newData to the end of the list
	- Parameter: a DataType variable to be added
	- Return: none
	*/
	void addEnd(KeyType newKey, DataType newData);

	/* Definition addAfter
	- It adds newNode after an existing node in the list
	- Parameter: 
	      + newData: the info being insterted into the list
	      + preData: the data to insert the newData after
	- Return: none
	*/
	void addAfter(KeyType newKey, DataType newData, KeyType preKey);

	/* Definition addToPos
	- It adds newNode to a specified position in the list
	- Parameters:
		  + newData: the info being insterted into the list
	      + pos: the position to insert the node in
	- Return: none
	*/
	void addToPos(KeyType newKey, DataType newData, int pos);

	/* Definition of deleteNode
		- It removes a Node from the list
		- Parameter: a Node variable to be deleted
		- Return: none
	*/
	void remove(KeyType deleteKey);

	/* Definition of find
		- It traverses through the list to find the Node
		- Parameter: a Node variable to be searched
		- Return: an int (for position of that Node in the list)
	*/
	int find(KeyType findKey);

	DataType* returnData(KeyType dataKey);

	/* Definition of emptyList
		- It removes all the Nodes in the list
		- Parameter: none
		- Return: none
	*/
	void emptyList();

	/* Definition of countNodes
		- It counts the total number of Nodes in the list by calling function getNodeCounter() from Head.h
		- Parameter: none
		- Return: an int (number of nodes)
	*/
	virtual int countNodes();

	/*
	Definition of overloaded operator<<
		- prints contents of the list
		- Parameter: none
		- Return: void
	*/
	template<class DataType, KeyType> friend ostream& operator<<(ostream&, const SinglyLinkedList<DataType, KeyType>&);
	
};



template <class DataType, class KeyType>
SinglyLinkedList<DataType, KeyType>::SinglyLinkedList()
{
}//end default contructor

template <class DataType, class KeyType>
SinglyLinkedList<DataType, KeyType>::~SinglyLinkedList()
{
	emptyList();
}//end deconstructor

template <class DataType, class KeyType>
void SinglyLinkedList<DataType, KeyType>::addTop(KeyType newKey, DataType newData)
{
	Node<DataType, KeyType>* newNode;
	newNode = new Node<DataType, KeyType>(newKey, newData, headNode.get_Front());
	headNode.set_Front(newNode);
	++headNode;
}//end addTop

template <class DataType, class KeyType>
void SinglyLinkedList<DataType, KeyType>::addEnd(KeyType newKey, DataType newData)
{
	Node<DataType, KeyType>* newNode;
	Node<DataType, KeyType>* temp_f = headNode.get_Front();

	newNode = new Node<DataType, KeyType>(newKey, newData, nullptr);
	while (temp_f->get_next() != nullptr)
	{
		temp_f = temp_f->get_next();
	}
	temp_f->set_next(newNode);
	++headNode;
}//end addEnd

template <class DataType, class KeyType>
void SinglyLinkedList<DataType, KeyType>::addAfter(KeyType newKey, DataType newData, KeyType preKey)
{
	Node<DataType, KeyType>* newNode;
	Node<DataType, KeyType>* temp_f = headNode.get_Front();
	Node<DataType, KeyType>* temp_b;

	if (find(preKey) != -1)
	{
		while (temp_f->get_key() != preKey)
		{
			temp_f = temp_f->get_next();
		}
		temp_b = temp_f;
		temp_f = temp_f->get_next();
		newNode = new Node<DataType, KeyType>(newKey, newData, temp_f);
		temp_b->set_next(newNode);

		++headNode;
	}
	else
	{
		cout << preData << " is not in the List";
	}
}//end addAfter

template <class DataType, class KeyType>
void SinglyLinkedList<DataType, KeyType>::addToPos(KeyType newKey, DataType newData, int pos)
{
	Node<DataType, KeyType>* newNode;
	Node<DataType, KeyType>* temp_f = headNode.get_Front();
	Node<DataType, KeyType>* temp_b;
	if (pos <= headNode.get_nodeCounter())
	{
		if (pos == 0)
		{
			newNode = new Node<DataType>(newKey, newData, headNode.get_Front());
			headNode.set_Front(newNode);
		}
		else
		{
			for (int i = 0; i < pos - 1; i++)
			{
				temp_f = temp_f->get_next();
			}
			temp_b = temp_f;
			temp_f = temp_f->get_next();
			newNode = new Node<DataType>(newKey, newData, temp_f);
			temp_b->set_next(newNode);

		}
		++headNode;
	}
	else
	{
		cout << "Error: position not in range.\n";
	}
}//end addToPos


template <class DataType, class KeyType>
void SinglyLinkedList<DataType, KeyType>::remove(KeyType deleteKey)
{
	Node<DataType, KeyType>* temp_f = headNode.get_Front();
	Node<DataType, KeyType>* temp_b;

	if (find(deleteKey) != -1)
	{

		if (temp_f->get_key() == deleteKey)
		{
			headNode.set_Front(temp_f->get_next());
			delete temp_f;
		}
		else 
		{
			while (temp_f->get_next()->get_key() != deleteKey)
			{
				temp_f = temp_f->get_next();
			}
			temp_b = temp_f;
			temp_f = temp_f->get_next();
			temp_b->set_next(temp_f->get_next());
			delete temp_f;
		}
		--headNode;
	}
	else
	{
		cout << "The data does not exist in the list";
	}
}//end remove


template <class DataType, class KeyType>
int SinglyLinkedList<DataType, KeyType>::find(KeyType findKey)
{
	int pos = 0;
	Node<DataType, KeyType>* temp = headNode.get_Front();

	while (temp->get_next() != nullptr)
	{
		if (temp->get_key() == findKey) return pos;

		temp = temp->get_next();
		pos++;
	}
	return -1;
}//end find

template <class DataType, class KeyType>
DataType* SinglyLinkedList<DataType, KeyType>::returnData(KeyType dataKey){
	Node<DataType, KeyType>* temp = headNode.get_Front();

	while (temp->get_next() != nullptr)
	{
		if (temp->get_key() == dataKey) return &(temp->get_data());

		temp = temp->get_next();
	}
	cout << "Not in list" << endl;
	return nullptr;
}


template <class DataType, class KeyType>
void SinglyLinkedList<DataType, KeyType>::emptyList()
{
	Node<DataType, KeyType>* temp_f = headNode.get_Front();
	Node<DataType, KeyType>* temp_b;

	cout << "\tEmptying list:" << endl;
	while (temp_f != nullptr)
	{
		temp_b = temp_f;
		temp_f = temp_f->get_next();
		cout << "\tRemoving " << temp_b->get_key() << endl;
		delete temp_b;
		--headNode;
	}
	headNode.set_Front(0);
	headNode.set_Rear(0);
}//end emptyList


template <class DataType, class KeyType>
int SinglyLinkedList<DataType, KeyType>::countNodes() 
{
	return headNode.get_nodeCounter();
}//end countNodes




template <class DataType, class KeyType>
ostream& operator<<(ostream& s, const SinglyLinkedList<DataType, KeyType>& list)
{
	Node<DataType, KeyType>* temp = list.headNode.get_Front();

	while (temp != nullptr)
	{
		s << temp->get_Key() << endl;
		temp = temp->get_next();
	}
	return s;
}

