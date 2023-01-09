#include "app.h"

int deleteIpMenu(MYSQL *conn){
  char id[4];

  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  nodelay(stdscr, FALSE);
  echo();

  selectIP("1", "1", conn); // show all IP (WHERE 1 = 1)

  printw("Please enter id (0 to exit): ");
  scanw("%s",id);

  if(strToInt(id) == 0){
    return EXIT_SUCCESS;
  }

  deleteIP(id, conn);

  exitMenu();

  nodelay(stdscr, TRUE);
  noecho();
  clear();
  delwin(w);
  return EXIT_SUCCESS;
}
