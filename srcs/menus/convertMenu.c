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
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip));

  printf("\nBinary: ");
  binaryIP(ipToStruct(buffer, "24"));
  printf("\nHexa: ");
  hexaIP(ipToStruct(buffer, "24"));
  printf("\nIP Type: ");
  ipType(ipToStruct(buffer, "24"));

  return EXIT_SUCCESS;
}
