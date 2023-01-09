#include "app.h"

int mainMenu(){
  WINDOW *w;
  // int LENGTH = 6;
  // int MAX_LETTER = 35;
  char list[6][35] = { "Show all saved IP", "Add IP", "Convert IP", "Filter saved IP with mask", "Delete saved IP", "Exit"};
  char item[35];
  int ch, i = 0;

  // initscr(); // initialize Ncurses
  w = newwin( 10, 40, 1, 1 ); // create a new window
  box( w, 0, 0 ); // sets default borders for the window
  // now print all the menu items and highlight the first one

  for( i=0; i<6; i++ ) {
    if( i == 0 ) {
      wattron( w, A_STANDOUT ); // highlights the first item.
    } else {
      wattroff( w, A_STANDOUT );
    }
    sprintf(item, "%s",  list[i]);
    mvwprintw( w, i+1, 2, "%s", item );
  }

  wrefresh( w ); // update the terminal screen
  i = 0;
  noecho(); // disable echoing of characters on the screen
  keypad( w, TRUE ); // enable keyboard input for the window.
  curs_set( 0 ); // hide the default screen cursor.
  // get the input

  while(( ch = wgetch(w)) != '\n'){
    // right pad with spaces to make the items appear with even width.
    sprintf(item, "%s",  list[i]);
    mvwprintw( w, i+1, 2, "%s", item );
    // use a variable to increment or decrement the value based on the input.

    switch( ch ) {
      case KEY_UP:
        i--;
        i = ( i<0 ) ? 5 : i;
        break;
      case KEY_DOWN:
        i++;
        i = ( i>5 ) ? 0 : i;
        break;
    }

    // now highlight the next item in the list.
    wattron( w, A_STANDOUT );
    sprintf(item, "%s",  list[i]);
    mvwprintw( w, i+1, 2, "%s", item);
    wattroff( w, A_STANDOUT );

  }

  clear();
  delwin( w );

  return i+1;
}
