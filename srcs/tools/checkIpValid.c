#include "app.h"

int checkIpValid(char *ip){
  char* delim = ".";
  char* ptr   = strtok(ip, delim);
  short i     = 0;
  int strInt;

  while (ptr != NULL) {
    strInt = strToInt(ptr);
    if(strInt > 254 || strInt <  0){ // if bit is between 254 & 0
      return EXIT_FAILURE;
    }
    if((strInt > 254 || strInt <  1) && (i == 0)){ // if bit is between 254 & 1 (only for the first bit)
      return EXIT_FAILURE;
    }
    ptr = strtok(NULL, delim);
    i++;
  }

  if(i != 4){ // if ip not contain 4 bit
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
