#include "app.h"

int selectMenu(MYSQL *conn){
  WINDOW *w;
  w = newwin( 10, 40, 1, 1 ); // create a new window

  logo(); // print app logo

  selectIP("1", "1", conn);

  exitMenu(); // prompt user for exit this menu

  clear(); // clear window
  delwin( w ); // delete window

  return EXIT_SUCCESS;
}
