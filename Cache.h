#ifndef CACHE_H
#define CACHE_H

#define CACHE_SIZE_EXP 15;
#define CACHE_SIZE (1 << 15);
#define ADDRESS_SIZE 32;

struct Block{
  bool m_valid;
  int m_tag;
};

class Cache{
private:
  //int cacheLines;
  //int associativity;
  int m_hits;
  int m_misses;
  void readBinFile();
  void replacement();


public:
  //Block m_cache[cacheLines][associativity];
  Cache();
  ~Cache();
};
#endif
