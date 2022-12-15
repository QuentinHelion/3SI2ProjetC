#include "app.h"

int checkMaskValid(char *mask){

  if(strToInt(mask) > 32){
    return EXIT_FAILURE;
  }

  if(strToInt(mask) < MIN_MASK_VALUE){
    return EXIT_FAILURE;
  }

  printf("%d\n", strToInt(mask));

  return EXIT_SUCCESS;
}
