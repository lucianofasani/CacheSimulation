#ifndef CACHE_H
#define CACHE_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define CACHE_SIZE_EXP 15
#define CACHE_SIZE (1 << 15)

#define ADDRESS_SIZE 32

#define CACHEASSOC_EXP 0
#define CACHEASSOC (1 << CACHEASSOC_EXP)

#define BLOCKSIZE_EXP 6
#define BLOCKSIZE_NBR (1 << BLOCKSIZE_EXP)
#define BLOCKSIZE_MASK (BLOCKSIZE_NBR - 1)

#define LINES_EXP ((CACHE_SIZE_EXP) - (CACHEASSOC_EXP + BLOCKSIZE_EXP))
#define LINES_NBR (1 << LINES_EXP)
#define LINES_MASK (LINES_NBR - 1)

#define TAG_EXP (ADDRESS_SIZE - BLOCKSIZE_EXP - LINES_EXP)
#define TAG_NBR (1 << TAG_EXP)
#define TAG_MASK (TAG_NBR - 1)

struct Block{
  bool m_valid;
  int m_tag;
};

class Cache{
private:
  double m_hits;
  double m_misses;
  void replacement();


public:
  Block m_cache[LINES_NBR][CACHEASSOC];
  Cache();
  ~Cache();
  void cacheSim();
  long binaryConversion(long num);
};
#endif
