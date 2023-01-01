#include "app.h"

int selectMenu(MYSQL *conn){
  char input;
  printw("%s",THEME_BAR_TOP);
  selectIP("1", "1", conn);

  printw("Press key to exit\n");
  scanw("%c",&input);
  clear();
  return EXIT_SUCCESS;
}
