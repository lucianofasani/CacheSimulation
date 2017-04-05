/**
*	@file : OpenHashTable.h
*	@author :  Denae Douglas
*	@date : 2017.01.29
*	Purpose: OpenHashTable Class declarations
*/
#ifndef HASHT_H
#define HASHT_H
#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"

class OpenHashTable{
private:
  int m_size;
  int data;
  DoubleLinkedList<int>* m_hashTb;

public:
  /**
  *  @pre None
  *  @post creates and initializes a hash table
  *  @return None
  */
  OpenHashTable();
  /**
  *  @pre None
  *  @post destroy hash table
  *  @return None
  */
  ~OpenHashTable();
  /**
  *  @pre None
  *  @post hashes the key
  *  @return the hashed value
  */
  int hash(int key);
  /**
  *  @pre None
  *  @post searches for the key in the hash table
  *  @return true if found, false otherwise
  */
  bool find(int key);
  /**
  *  @pre None
  *  @post None
  *  @return the number of values in the hash table
  */
  int size();
  /**
  *  @pre None
  *  @post None
  *  @return None
  */
  void print();
  /**
  *  @pre None
  *  @post inserts the value into the hash table
  *  @return None
  */
  void insert(int key);
  /**
  *  @pre None
  *  @post removes value from the hash table
  *  @return None
  */
  void remove(int key);



};
#endif
