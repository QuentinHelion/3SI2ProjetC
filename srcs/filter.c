#include "app.h"

int filterMask(char *value, MYSQL *conn){

  selectIP("mask", value, conn);

  return EXIT_SUCCESS;
}
