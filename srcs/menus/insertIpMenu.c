#include "app.h"

int insertIpMenu(MYSQL *conn){
  char ip[16];
  char mask[3];
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

  do {
    printf("Please enter mask: ");
    fgets(mask, 3, stdin);
    fgetc(stdin);
  } while(checkMaskValid(mask)); // if entry is good we can leave the loop

  insertIP(ipToStruct(buffer, mask), conn);

  fgetc(stdin); // clean input
  return EXIT_SUCCESS;
}
