/**
*	@file : Cache.cpp
*	@author :  Denae Douglas, Keshawn Triplett, Luciano Fasani
*	@date : 2017.04.11
*	Purpose: Cache class implementation
*/
#include "Cache.h"
Cache::Cache(){

}

Cache::~Cache(){

}

void Cache::cacheSim(){
  FILE * pFile;
  size_t result = 1;
  uint32_t address;
  double counter = 0;

  pFile = fopen ( "/home/denaedouglas/Documents/EECS_645/AddressTrace_LastIndex.bin" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  std::cout << "\n";
  while(result != 0){
    result = fread (&address,4,1,pFile);

    //bit shifting the offset
    for(int i = 0; i < 6; i++){
      address = floor(address/2);
    }

    //bitwise and the address with the number of lines in the cache - 1
    ALINE = (address & LINES_MASK);

    //bit shift the line bits
    for(int i = 0; i < LINES_EXP; i++){
      address = floor(address/2);
    }

    ATAG = address;

    for(int i = 0; i < CACHEASSOC; i++){
      if(m_cache[ALINE][i].m_valid == true){
        if(m_cache[ALINE][i].m_tag == ATAG){
          m_hits++;
          break;
        }
        else{
          if(i == CACHEASSOC-1){//if the last block's tag != TAG log a miss
            m_misses++;
            replacement();
          }
        }
      }
      else {
        m_cache[ALINE][i].m_valid = true;
        m_cache[ALINE][i].m_tag = ATAG;
        m_misses++;
        break;
      }
    }//end for loop
    counter++;
  }//while loop
  std::cout << "Hits: " << m_hits << "\n";
  std::cout << "Misses:" << m_misses << "\n";
  std::cout << "Hits/Accesses: " << (m_hits/counter) << "\n";
  std::cout << "Misses/Accesses: " << (m_misses/counter) << "\n";
}

void Cache::replacement(){
  if(CACHEASSOC_EXP == 0){
    m_cache[ALINE][0].m_tag = ATAG;
  }
  else{
    double random = (double)rand()/RAND_MAX;
    if(random >= 0 && random < 0.5){
      m_cache[ALINE][0].m_tag = ATAG;
    }
    else{
      m_cache[ALINE][1].m_tag = ATAG;
    }
  }
}
