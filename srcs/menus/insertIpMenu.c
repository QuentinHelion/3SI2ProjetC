#include "app.h"

int insertIpMenu(MYSQL *conn){
  char ip[16];
  char mask[3];
  char buffer[16];
  WINDOW *w;

  w = newwin( 50, 40, 1, 1 ); // create a new window
  nodelay(stdscr, FALSE); // needed to show user input on window
  echo();

  logo(); // print app logo

  do {
    printw("Please enter IP: ");
    scanw("%s",ip);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip)); // if entry is good we can leave the loop

  do {
    printw("Please enter mask: ");
    scanw("%s",mask);
  } while(checkMaskValid(mask)); // if entry is good we can leave the loop

  insertIP(ipToStruct(buffer, mask), conn);

  clear(); // clear window
  delwin( w ); // delete window

  return EXIT_SUCCESS;
}
