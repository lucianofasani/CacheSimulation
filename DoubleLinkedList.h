/**
*	@file : DoubleLinkedList.h
*	@author :  Denae Douglas
*	@date : 2017.01.29
*	Purpose: DoubleLinkedList Class declarations
*/
#ifndef DLL_H
#define DLL_H
#include "Node.h"
#include <stdexcept>
template <typename T>

class DoubleLinkedList{
private:
	Node <T>* m_front;
	Node <T>* m_back;
	int m_size;

public:
	/**
	*  @pre None
	*  @post creates and initializes a DoubleLinkedList class
	*  @return None
	*/
	DoubleLinkedList();

	/**
	*  @pre None
	*  @post destroys all nodes in the list
	*  @return None
	*/
	~DoubleLinkedList();

	/**
	*  @pre Node in the list
	*  @post  None
	*  @return true if list is empty, false otherwise
	*/
	bool isEmpty() const;

	/**
	*  @pre None
	*  @post calculates number of elements in the list
	*  @return integer indicating size of list
	*/
	int size() const;

	/**
	*  @pre None
	*  @post adds a Node to the front of the list if T not found
	*  @return None
	*/
	void insert(T value);

	/**
	*  @pre None
	*  @post reverses the list
	*  @return None
	*/
	void reverse(Node<T>* traverse);

	//calls the above reverse method for recursion
	void reverse();

	/**
	*  @pre must be a node in the list
	*  @post One element is removed from the list
	*  @return Returns true if the element was removed, false otherwise
	*/
	void deletenode(T value, Node<T>* traverse);

	//calls the above deletenode method for recursion
	void deletenode(T value);

	/**
	*  @pre None
	*  @post adds a Node to the back of the list
	*  @return None
	*/
	void print(Node<T>* traverse) const;

	//calls the above print method for recursion
	void print() const;

	/**
	*  @pre None
	*  @post hash function using the mod (%) operator
	*  @return index for key x
	*/
	int hash(T value, int m);

	/**
	*  @pre None
	*  @post search for the key in the hash table
	*  @return true if it is found and false if not
	*/
	bool find(T value);
};
#include "DoubleLinkedList.hpp"
#endif
