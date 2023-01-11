#include "app.h"

int logo(){
  init_pair(2, COLOR_YELLOW, COLOR_BLACK); // create color (text + background)

  attron(COLOR_PAIR(2)); // set color
  printw( "\
    _____          _____                      \n\
   |_   _|        / ____|                     \n\
     | |  _ __   | (___   __ ___   _____ _ __ \n\
     | | | '_ \\   \\___ \\ / _` \\ \\ / / _ \\ '__|\n\
    _| |_| |_) |  ____) | (_| |\\ V /  __/ |   \n\
   |_____| .__/  |_____/ \\__,_| \\_/ \\___|_|   \n\
         | |                                  \n\
         |_|\
    \n\n");

  attron(COLOR_PAIR(1));

  // endwin();

  return EXIT_SUCCESS;
}
