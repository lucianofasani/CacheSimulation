/**
*	@file : OpenHashTable.cpp
*	@author :  Denae Douglas
*	@date : 2017.01.29
*	Purpose: OpenHashTable Class Implementation
*/
#include "OpenHashTable.h"

OpenHashTable::OpenHashTable(){
  m_size = 256;//for 2 way set associative
  m_hashTb = new DoubleLinkedList<int>[m_size];
}

OpenHashTable::~OpenHashTable(){
  for (int i = 0; i < m_size; i++) {
    m_hashTb[i].~DoubleLinkedList();
  }
  delete[] m_hashTb;
}

int OpenHashTable::hash(int key){
  return(key % m_size);
}

bool OpenHashTable::find(int key){
  return m_hashTb[hash(key)].find(key);//the find being called in this line is a call to DoubleLinkedList's find function
}

int OpenHashTable::size(){
  return(m_size);
}

void OpenHashTable::print(){
  for(int i = 0; i < m_size; i++){
    std::cout << i << ": ";
    m_hashTb[i].print();
    std::cout << "\n";
  }
}

void OpenHashTable::insert(int key){
  if(find(key) == false){//the find in this line is a call to OpenHashTable's find function
    m_hashTb[hash(key)].insert(key);
  }
}

void OpenHashTable::remove(int key){
  m_hashTb[hash(key)].deletenode(key);
}
