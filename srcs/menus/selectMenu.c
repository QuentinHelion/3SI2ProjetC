#include "app.h"

int selectMenu(MYSQL *conn){
  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window

  selectIP("1", "1", conn);

  exitMenu();

  clear();
  delwin( w );

  return EXIT_SUCCESS;
}
