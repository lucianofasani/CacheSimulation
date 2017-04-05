#ifndef CACHE_H
#define CACHE_H
#include "OpenHashTable.h"

class Cache{
private:
  int cacheLines;
  int associativity;
  void readBinFile();
  void replacement();


public:
  Cache();
  ~Cache();
};
#endif
