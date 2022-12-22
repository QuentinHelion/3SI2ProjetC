#include "app.h"

int checkMaskValid(char *mask){

  if(strToInt(mask) > MAX_MASK_VALUE){ // if more than max
    return EXIT_FAILURE; // not okay == faillure
  }

  if(strToInt(mask) < MIN_MASK_VALUE){ // if less than min
    return EXIT_FAILURE; // not okay == faillure
  }

  return EXIT_SUCCESS;
}
