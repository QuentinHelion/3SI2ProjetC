#include "app.h"

int catalogMenu(){
  WINDOW *w;
  char list[3][35] = { "Show all IP", "Filter saved IP with mask", "Return"};
  char item[35];
  int ch, i = 0;

  w = newwin( 5, 40, 1, 1 ); // create a new window
  box( w, 0, 0 ); // sets default borders for the window
  for( i=0; i<3; i++ ) {
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

  while(( ch = wgetch(w)) != '\n'){
    sprintf(item, "%s",  list[i]); // convert list[i] to string & save on item variable
    mvwprintw( w, i+1, 2, "%s", item ); // use a variable to increment or decrement the value based on the input.

    switch( ch ) {
      case KEY_UP:
        i--;
        i = ( i<0 ) ? 2 : i;
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

  clear(); // clear window
  delwin( w ); // delete window

  return i+1;
}
