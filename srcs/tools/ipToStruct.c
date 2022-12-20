#include "app.h"

ip_addr ipToStruct(char *ip, char *mask){
  char* delim = "."; // ip delimiter
  char* ptr   = strtok(ip, delim); // stock ip on ptr
  int i       = 0;
  int strInt;
  int bitArray[4];
  ip_addr addrStruct;

  while (ptr != NULL) {
    strInt = strToInt(ptr);
    ptr = strtok(NULL, delim);
    bitArray[i] = strInt;
    i++;
  }

  // stock all values on struct
  addrStruct.addr[0] = bitArray[0];
  addrStruct.addr[1] = bitArray[1];
  addrStruct.addr[2] = bitArray[2];
  addrStruct.addr[3] = bitArray[3];
  addrStruct.mask    = strToInt(mask);

  return addrStruct;
}
