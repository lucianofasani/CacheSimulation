/**
*	@file : Node.hpp
*	@author :  Denae Douglas
*	@date : 2015.09.28
*	Purpose: Implementation of Node Class
*/
template <typename T>
Node<T>::Node(){
	m_next = nullptr;
	m_previous = nullptr;
	m_value = T();
}

template <typename T>
T Node<T>::getValue() const{
	return(m_value);
}

template <typename T>
void Node<T>::setValue(T value){
	m_value = value;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
	return(m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next){
	m_next = next;
}

template <typename T>
Node<T>* Node<T>::getPrevious() const{
	return(m_previous);
}

template <typename T>
void Node<T>::setPrevious(Node<T>* previous){
	m_previous = previous;
}
