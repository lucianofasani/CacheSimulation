#include "Cache.h"
#include <math.h>
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

  //printf("%x\n", (0110 & 1111));
  std::cout << "\n";
  while(result != 0){
    result = fread (&address,4,1,pFile);

    //printf("%x\n", address);

    //(address >> 6);
    for(int i = 0; i < 6; i++){
      address = floor(address/2);
    }

    uint32_t LINE = (address & 511);
    //std::cout << "Line: " << LINE << "\n";

    //(address >> 8);
    for(int i = 0; i < 9; i++){
      address = floor(address/2);
    }
    uint32_t TAG = address;
    //uint32_t TAG = (address & 111111111111111111);
    //std::cout << "Tag: " << TAG << "\n";

    for(int i = 0; i < CACHEASSOC; i++){
      if(m_cache[LINE][i].m_valid == true){
        if(m_cache[LINE][i].m_tag == TAG){
          m_hits++;
          break;
        } else {
          m_cache[LINE][i].m_valid = true;
          m_cache[LINE][i].m_tag = TAG;
          m_misses++;
          break;
        }
      } else {
        m_cache[LINE][i].m_valid = true;
        m_cache[LINE][i].m_tag = TAG;
        m_misses++;
        break;
      }
      /*
      if(m_cache[LINE][i].m_valid == true){
        if(m_cache[LINE][i].m_tag == TAG){
          m_hits++;
          break;
        }
        else{
          m_cache[LINE][i].m_valid = true;
          m_cache[LINE][i].m_tag = TAG;
          m_misses++;
        }
      }
      else{
        m_misses++
        break;
      }
      */

    }

    counter++;
  }
  std::cout << "Hits: " << m_hits << "\n";
  std::cout << "Misses:" << m_misses << "\n";
  std::cout << counter << "\n";
  std::cout<< (m_hits/counter);
}

void Cache::replacement(){

}

long Cache::binaryConversion(long num){
  long binaryNum;
  long decimalNum = 0;
  long rem;
  long base = 1;

  binaryNum = num;

  while(num > 0){
    rem = num % 10;
    decimalNum = decimalNum + rem * base;
    base = base * 2;
    num = num / 10;
  }

  return(decimalNum);
}
