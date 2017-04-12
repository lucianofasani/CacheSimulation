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
  int iterations = 0;

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
      iterations++;
      if(m_cache[ALINE][i].m_valid == true){
        if(m_cache[ALINE][i].m_tag == ATAG){
          m_hits++;
          break;
        }
        else{
          /*if(CACHEASSOC_EXP == 0){
            m_misses++;
          }*/
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
  std::cout << "For Loop Iterations: " << iterations << "\n";
  std::cout << "Counter: " << counter << "\n";
  std::cout << "Hits/Entries: " << (m_hits/counter) << "\n";
}

//call this if associativity != 0 and neithr block has a matching tag but both have something in them
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
