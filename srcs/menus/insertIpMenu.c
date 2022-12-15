#include "app.h"

int insertIpMenu(){
  char ip[15];
  char mask[2];

  printf("\n========oOo========\n");

  do {
    printf("Please enter IP: ");
    fgets(ip, 15, stdin);
    fgetc(stdin);
  } while(checkIpValid(ip));


  do {
    printf("Please enter mask: ");
    fgets(mask, 2, stdin);
    fgetc(stdin);
  } while(checkMaskValid(mask));

  fgetc(stdin);
  return EXIT_SUCCESS;
}
