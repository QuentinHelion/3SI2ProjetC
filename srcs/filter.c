#include "app.h"

int filterMask(char *value, MYSQL *conn){

  selectIP("mask", value, conn); // call select function with mask column for filter

  return EXIT_SUCCESS;
}
