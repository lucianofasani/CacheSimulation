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
	m_tag = T();
	m_valid = false;
}

template <typename T>
T Node<T>::getTag() const{
	return(m_tag);
}

template <typename T>
void Node<T>::setTag(T tag){
	m_tag = tag;
}

template <typename T>
bool Node<T>::getState() const{
	return(m_valid);
}

template <typename T>
void Node<T>::setState(bool state){
	m_valid = state;
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
