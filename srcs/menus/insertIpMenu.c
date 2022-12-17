#include "app.h"

int insertIpMenu(){
  char ip[16];
  char mask[3];

  printf("\n========oOo========\n");

  do {
    printf("Please enter IP: ");
    fgets(ip, 16, stdin);
    fgetc(stdin);
  } while(checkIpValid(ip));


  do {
    printf("Please enter mask: ");
    fgets(mask, 3, stdin);
    fgetc(stdin);
  } while(checkMaskValid(mask));

  fgetc(stdin);
  return EXIT_SUCCESS;
}
