#include "app.h"

int strToInt(char *value){
  int result;
  sscanf(value, "%d", &result); // convert str value to int value

	return result;
}
