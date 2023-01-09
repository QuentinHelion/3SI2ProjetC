#include "app.h"

int selectMenu(MYSQL *conn){
  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  // box( w, 0, 0 ); // sets default borders for the window

  // printw("%s",THEME_BAR_TOP);
  selectIP("1", "1", conn);

  exitMenu();

  clear();
  delwin( w );
  
  return EXIT_SUCCESS;
}
