/**
*	@file : Node.h
*	@author :  Denae Douglas
*	@date : 2015.09.28
*	Purpose: Node Class declarations
*/
#ifndef NODE_H
#define NODE_H
#include <string>

template <typename T>
class Node{
	private:
	T m_tag;
	bool m_valid;
	Node<T>* m_previous;
	Node<T>* m_next;

	public:
	/**
	*  @pre None
	*  @post creats a Node
	*  @return None
	*/
	Node();

	/**
	*  @pre Node must be created
	*  @post sets value of tag within a Node
	*  @return None
	*/
	void setTag(T tag);

	/**
	*  @pre Node must be created
	*  @post used to get the tag inside of a Node
	*  @return an integer
	*/
	T getTag() const;

	/**
	*  @pre Node must be created
	*  @post sets value of tag within a Node
	*  @return None
	*/
	void setState(bool state);

	/**
	*  @pre Node must be created
	*  @post used to get the tag inside of a Node
	*  @return an integer
	*/
	bool getState() const;

	/**
	*  @pre Node must be created
	*  @post sets the value of the Node pointer
	*  @return None
	*/
	void setNext(Node<T>* next);

	/**
	*  @pre Node must be created
	*  @post get to what the Node pointer is pointing to
	*  @return value of what the Node pointer is pointing to
	*/
	Node<T>* getNext() const;

	/**
	*  @pre Node must be created
	*  @post sets the value of the Node pointer to the previous Node
	*  @return None
	*/
	void setPrevious(Node<T>* previous);

	/**
	*  @pre Node must be created
	*  @post get to what the Node pointer is pointing to
	*  @return value of what the Node pointer is pointing to
	*/
	Node<T>* getPrevious() const;

};
#include "Node.hpp"
#endif
