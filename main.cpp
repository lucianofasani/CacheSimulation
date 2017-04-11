//the following code comes from cplusplus reference: http://www.cplusplus.com/reference/cstdio/fread/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main () {

  //Convert a binary number to decimal

  long bin, dec = 0, rem, num, base = 1;

  std::cout << "Enter the binary number(1s and 0s) : ";
  std::cin >> num;
  bin = num;
  while (num > 0)
  {
      rem = num % 10;
      dec = dec + rem * base;
      base = base * 2;
      num = num / 10;
  }
  std::cout << "The decimal equivalent of " << bin << " : " << dec << "\n";

  return 0;
}
