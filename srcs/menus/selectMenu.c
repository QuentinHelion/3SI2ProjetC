#include "app.h"

int selectMenu(MYSQL *conn){
  char input;
  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  box( w, 0, 0 ); // sets default borders for the window
  
  // printw("%s",THEME_BAR_TOP);
  selectIP("1", "1", conn);

  printw("Press key to exit\n");
  scanw("%c",&input);

  clear();
  delwin( w );
  return EXIT_SUCCESS;
}
