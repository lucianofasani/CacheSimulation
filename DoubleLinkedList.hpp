/**
*	@file : DoubleLinkedList.hpp
*	@author :  Denae Douglas
*	@date : 2017.01.29
*	Purpose: Implementation of DoubleLinkedList Class
*/
#include <iostream>
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	while(m_front != nullptr){
		deletenode(m_front->getTag());
	}
}


template <typename T>
bool DoubleLinkedList<T>::isEmpty() const{
	if(m_front == nullptr && m_back == nullptr){
		return(true);
	}
	else{
		return(false);
	}
}

template <typename T>
int DoubleLinkedList<T>::size() const{
	return(m_size);
}

template <typename T>
void DoubleLinkedList<T>::insert(T value){
	if(isEmpty()){
		m_front = new Node<T>();
		m_front -> setTag(value);
		m_back = m_front;
		m_size++;
	}
	else{
		Node<T>* newFront = new Node<T>();
		Node<T>* tempFront = m_front;
		newFront -> setNext(tempFront);
		newFront -> setTag(value);
		newFront -> setPrevious(nullptr);
		m_front = newFront;
		m_back = tempFront;
		tempFront -> setPrevious(newFront);
		m_size++;
	}
}

template <typename T>
void DoubleLinkedList<T>::print() const{
	print(m_front);
}

template <typename T>
void DoubleLinkedList<T>::print(Node<T>* traverse) const{
	if(isEmpty()){
		std::cout << "";
	}

	else{
		std::cout << traverse->getTag() << " ";
		if(traverse->getNext() != nullptr){
			print(traverse->getNext());
		}
	}
}

template <typename T>
void DoubleLinkedList<T>::deletenode(T value){
	deletenode(value, m_front);
}

template <typename T>
void DoubleLinkedList<T>::deletenode(T value, Node<T>* traverse){
	if(isEmpty()){
		return;
	}
	else{
		if(traverse->getTag() != value && traverse->getNext() != nullptr){
			deletenode(value, traverse->getNext());
		}
		else if(traverse->getNext() == nullptr && traverse->getTag() != value){
			std::cout << "Couldn't remove value \n";
		}
		else if(traverse->getTag() == value){
			Node<T>* nextPtr = traverse->getNext();
			Node<T>* prevPtr = traverse->getPrevious();

			if(nextPtr != nullptr){
				nextPtr->setPrevious(prevPtr);
			}
			else{
				m_back = traverse->getPrevious();
			}
			if(prevPtr != nullptr){
				prevPtr->setNext(nextPtr);
			}
			else{
				m_front = traverse->getNext();
			}
			m_size--;
			delete (traverse);
		}
	}
}

template <typename T>
void DoubleLinkedList<T>::reverse(){
	reverse(m_back);
}

template <typename T>
void DoubleLinkedList<T>::reverse(Node<T>* traverse){
	if(isEmpty() || size() == 1){
		std::cout << "";
	}
	else{
		if(traverse == m_back){
			reverse(traverse->getPrevious());
		}
		else if(traverse == m_front){
			Node<T>* tempFront = m_front;
			Node<T>* tempBack = m_back;
			m_front = tempFront->getNext();
			tempFront->getNext()->setPrevious(nullptr);
			tempBack->setNext(tempFront);
			tempFront->setNext(nullptr);
			tempFront->setPrevious(tempBack);
			m_back = tempFront;
		}
		else{
			Node<T>* tempBack = m_back;
			Node<T>* methodPtr = m_front; //the one before traverse that will be in the next method call

			while(methodPtr->getNext() != traverse){
				methodPtr = methodPtr->getNext();
			}

			traverse->getNext()->setPrevious(methodPtr);
			traverse->getPrevious()->setNext(traverse->getNext());
			tempBack->setNext(traverse);
			traverse->setPrevious(tempBack);
			traverse->setNext(nullptr);
			m_back = traverse;
			reverse(methodPtr);
		}
	}
}

template <typename T>
bool DoubleLinkedList<T>::find(T value){
	if(isEmpty()){
			return(false);
	}
	else{
		Node<T>* traverse = m_front;
		int i = 1;
		while(traverse->getTag() != value && i < size()){
			traverse = traverse->getNext();
			i++;
		}
		if(traverse->getTag() == value){
			return(true);
		}
		else{
			return(false);
		}
	}
}
