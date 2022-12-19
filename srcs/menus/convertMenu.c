#include "app.h"

int convertMenu(){
  char ip[16];
  char buffer[16];
  // ip_addr addr;

  printf("\n========oOo========\n");

  do {
    printf("Please enter IP: ");
    fgets(ip, 16, stdin);
    fgetc(stdin);
    printf("%s\n", ip);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip));

  printf("%s\n", buffer);

  binaryIP(ipToStruct(buffer, "24"));
  hexaIP(ipToStruct(buffer, "24"));

  return EXIT_SUCCESS;
}
