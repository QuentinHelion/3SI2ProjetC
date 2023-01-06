#include "app.h"

int insertIpMenu(MYSQL *conn){
  char ip[16];
  char mask[3];
  char buffer[16];

  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  // box( w, 0, 0 ); // sets default borders for the window


  // endwin();
  nodelay(stdscr, FALSE);
  echo();
  // printf("%s",THEME_BAR_TOP);

  do {
    // printf("Please enter IP: ");
    // fgets(ip, 16, stdin);
    // fgetc(stdin);
    printw("Please enter IP: ");
    // refresh();
    scanw("%s",ip);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip)); // if entry is good we can leave the loop

  do {
    // printf("Please enter mask: ");
    // fgets(mask, 3, stdin);
    // fgetc(stdin);
    printw("Please enter mask: ");
    // refresh();
    scanw("%s",mask);
  } while(checkMaskValid(mask)); // if entry is good we can leave the loop

  insertIP(ipToStruct(buffer, mask), conn);

  // fgetc(stdin); // clean input

  nodelay(stdscr, TRUE);
  noecho();
  clear();
  delwin(w);
  return EXIT_SUCCESS;
}
