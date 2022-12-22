#include "app.h"

int deleteIpMenu(MYSQL *conn){
  char id[4];

  selectIP("1", "1", conn); // show all IP

  printf("%s",THEME_BAR_TOP);
  printf("Please enter id (0 to exit): ");
  fgets(id, 4, stdin);
  fgetc(stdin);

  if(strToInt(id) == 0){
    return EXIT_SUCCESS;
  }

  deleteIP(id, conn);

  fgetc(stdin); // clean input
  return EXIT_SUCCESS;
}
