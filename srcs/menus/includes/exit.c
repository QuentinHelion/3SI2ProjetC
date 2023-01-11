#include "app.h"

int exitMenu(){
  char input;

  printw("Press key to exit\n");
  scanw("%c",&input);

  return EXIT_SUCCESS;
}
