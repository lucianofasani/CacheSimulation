#include "Cache.h"

Cache::Cache(){

}

Cache::~Cache(){

}

void Cache::cacheSim(){
  FILE * pFile;
  size_t result;
  uint32_t address;
  int counter = 0;


  pFile = fopen ( "/home/denaedouglas/Documents/EECS_645/AddressTrace_RandomIndex.bin" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  while(counter < 5){
    result = fread (&address,4,1,pFile);
    (address >> 6);
    uint32_t LINE = (address & LINES_MASK);
    (address >> LINES_EXP);
    uint32_t TAG = (address & TAG_MASK);
    counter++;
  }
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