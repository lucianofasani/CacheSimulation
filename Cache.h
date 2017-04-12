#ifndef CACHE_H
#define CACHE_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

//definitions provided by Professor Gary J. Minden
#define CACHE_SIZE_EXP 15
#define CACHE_SIZE (1 << 15)

#define ADDRESS_SIZE 32

#define CACHEASSOC_EXP 1
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
  uint32_t m_tag;
};

class Cache{
private:
  uint32_t ALINE;
  uint32_t ATAG;
  double m_hits;
  double m_misses;
  void replacement();


public:
  Block m_cache[LINES_NBR][CACHEASSOC];
  Cache();
  ~Cache();
  void cacheSim();
};
#endif
