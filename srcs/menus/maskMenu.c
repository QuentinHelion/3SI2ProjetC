#include "app.h"

int maskMenu(MYSQL *conn){
  char mask[3];

  printf("\n========oOo========\n");
  do {
    printf("Please enter mask: ");
    fgets(mask, 3, stdin);
    fgetc(stdin);
  } while(checkMaskValid(mask));

  filterMask(mask,conn);

  fgetc(stdin);
  return EXIT_SUCCESS;
}
