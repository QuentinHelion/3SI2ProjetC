#include "app.h"

int maskMenu(MYSQL *conn){
  char mask[3];

  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  // box( w, 0, 0 ); // sets default borders for the window


  nodelay(stdscr, FALSE);
  echo();

  // printf("%s",THEME_BAR_TOP);
  do {
    // printf("Please enter mask: ");
    // fgets(mask, 3, stdin);
    // fgetc(stdin);
    printw("Please enter mask: ");
    scanw("%s",mask);
  } while(checkMaskValid(mask));

  filterMask(mask,conn);


  exitMenu();

  clear();
  delwin(w);
  return EXIT_SUCCESS;
}
