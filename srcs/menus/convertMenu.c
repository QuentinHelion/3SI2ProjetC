#include "app.h"

int convertMenu(){
  char ip[16];
  char buffer[16];

  printf("%s",THEME_BAR_TOP);
  do {
    printf("Please enter IP: ");
    fgets(ip, 16, stdin);
    fgetc(stdin);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip)); // if entry is good we can leave the loop

  // === Call convertion function ===
  printf("\nBinary: ");
  binaryIP(ipToStruct(buffer, "24")); // Binary convertion
  printf("\nHexa: ");
  hexaIP(ipToStruct(buffer, "24")); // Hexa convertion

  // === Show ip type ===
  // Public, private, special, loopback, apipa
  printf("\nIP Type: ");
  ipType(ipToStruct(buffer, "24"));

  return EXIT_SUCCESS;
}
