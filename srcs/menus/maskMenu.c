#include "app.h"

int maskMenu(MYSQL *conn){
  char mask[3];

  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window

  logo(); // print app logo

  nodelay(stdscr, FALSE); // needed to show user input on window
  echo();

  do {
    printw("Please enter mask: ");
    scanw("%s",mask);
  } while(checkMaskValid(mask));

  filterMask(mask,conn);

  exitMenu(); // prompt user for exit this menu

  clear(); // clear window
  delwin( w ); // delete window

  return EXIT_SUCCESS;
}
