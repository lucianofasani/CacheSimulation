//the following code comes from cplusplus reference: http://www.cplusplus.com/reference/cstdio/fread/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main () {
  FILE * pFile;
  size_t result;
  uint32_t address;
  uint32_t numOfAddresses = 0;


  pFile = fopen ( "/home/denaedouglas/Documents/EECS_645/AddressTrace_RandomIndex.bin" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  std::cout << "Reading in addresses -- 1 by 1...\n";
  while(result != 0){
    result = fread (&address,4,1,pFile);
    numOfAddresses++;
  }

  std::cout << "Number of Addresses: " << numOfAddresses << "\n";

  int cache = 15;
  int cacheNbr = (1 << cache);
  std::cout << "Size of Cache: " << cacheNbr;
  return 0;
}
