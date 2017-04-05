//the following code comes from cplusplus reference: http://www.cplusplus.com/reference/cstdio/fread/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main () {
  FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen ( "/home/denaedouglas/Documents/EECS_645/AddressTrace_LastIndex.bin" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

	std::cout << "Size of file: " << lSize << "\n";

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,4,lSize,pFile);

	//this line will show how many addresses were read into memory
	std::cout << "Number of Addresses: " << result << "\n";
  /* the whole file is now loaded in the memory buffer. */

  // terminate
  fclose (pFile);
  free (buffer);
  return 0;
}

