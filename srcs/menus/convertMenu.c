#include "app.h"

int convertMenu(){
  char ip[16];
  char buffer[16];

  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  nodelay(stdscr, FALSE);
  echo();

  do {
    printw("Please enter IP: ");
    scanw("%s",ip);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip)); // if entry is good we can leave the loop

  // === Call convertion function ===
  printw("\nBinary: ");
  binaryIP(ipToStruct(buffer, "24")); // Binary convertion
  printw("\nHexa: ");
  hexaIP(ipToStruct(buffer, "24")); // Hexa convertion

  // === Show ip type ===
  // Public, private, special, loopback, apipa
  printw("\nIP Type: ");
  ipType(ipToStruct(buffer, "24"));

  exitMenu();

  nodelay(stdscr, TRUE);
  noecho();
  clear();
  delwin(w);

  return EXIT_SUCCESS;
}
