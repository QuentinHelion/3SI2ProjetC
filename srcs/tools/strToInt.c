#include "app.h"

int strToInt(char *value){
  int result;
  sscanf(value, "%d", &result);

  // printf("\nThe value of x : %d", result);

	return result;
}
