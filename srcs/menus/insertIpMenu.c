#include "app.h"

int insertIpMenu(MYSQL *conn){
  char ip[16];
  char mask[3];
  char buffer[16];
  // ip_addr addrStruct;

  printf("\n========oOo========\n");

  do {
    printf("Please enter IP: ");
    fgets(ip, 16, stdin);
    fgetc(stdin);
    // printf("%s\n", ip);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip));

  // printf("%s\n", ip);
  printf("%s\n", buffer);

  do {
    printf("Please enter mask: ");
    fgets(mask, 3, stdin);
    fgetc(stdin);
  } while(checkMaskValid(mask));



  // addrStruct = ipToStruct(ip, mask);
  //
  // printf("%d\n", addrStruct.addr[0]);

  insertIP(ipToStruct(buffer, mask), conn);

  fgetc(stdin);
  return EXIT_SUCCESS;
}
