#include "app.h"

ip_addr ipToStruct(char *ip, char *mask){
  char* delim = ".";
  char* ptr   = strtok(ip, delim);
  int strInt;
  int i = 0;
  int bitArray[4];
  ip_addr addrStruct;

  while (ptr != NULL) {
    // printf("'%s'\n", ptr);
    strInt = strToInt(ptr);
    ptr = strtok(NULL, delim);
    bitArray[i] = strInt;
    printf("%d\n", strInt);
    i++;
  }

  addrStruct.addr[0] = bitArray[0];
  addrStruct.addr[1] = bitArray[1];
  addrStruct.addr[2] = bitArray[2];
  addrStruct.addr[3] = bitArray[3];
  addrStruct.mask = strToInt(mask);


  return addrStruct;
}
