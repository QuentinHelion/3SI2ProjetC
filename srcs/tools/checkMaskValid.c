#include "app.h"

int checkMaskValid(char *mask){

  if(strToInt(mask) > MAX_MASK_VALUE){
    return EXIT_FAILURE;
  }

  if(strToInt(mask) < MIN_MASK_VALUE){
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
