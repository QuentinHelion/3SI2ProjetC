#include "app.h"

int checkIpValid(char *ip){
  char* delim = ".";
  char* ptr   = strtok(ip, delim);
  short i     = 0;
  int strInt;

  // printf("'%s'\n", ip);
  while (ptr != NULL) {
    // printf("'%s'\n", ptr);
    strInt = strToInt(ptr);
    if(strInt > 254 || strInt <  1){
      return EXIT_FAILURE;
    }
    ptr = strtok(NULL, delim);
    i++;
  }

  if(i != 4){
    return EXIT_FAILURE;
  }


  return EXIT_SUCCESS;
}
