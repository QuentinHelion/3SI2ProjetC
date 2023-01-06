#include "app.h"

int convertMenu(){
  char ip[16];
  char buffer[16];
  char input;

  // printf("%s",THEME_BAR_TOP);
  WINDOW *w;
  w = newwin( 50, 40, 1, 1 ); // create a new window
  nodelay(stdscr, FALSE);
  echo();

  do {
    // printf("Please enter IP: ");
    // fgets(ip, 16, stdin);
    // fgetc(stdin);
    printw("Please enter IP: ");
    scanw("%s",ip);
    for (short i = 0; i < 16; i++) {
      buffer[i] = ip[i];
    }
  } while(checkIpValid(ip)); // if entry is good we can leave the loop

  // === Call convertion function ===
  // printf("\nBinary: ");
  printw("\nBinary: ");
  binaryIP(ipToStruct(buffer, "24")); // Binary convertion
  // printf("\nHexa: ");
  printw("\nHexa: ");
  hexaIP(ipToStruct(buffer, "24")); // Hexa convertion

  // === Show ip type ===
  // Public, private, special, loopback, apipa
  // printf("\nIP Type: ");
  printw("\nIP Type: ");
  ipType(ipToStruct(buffer, "24"));

  printw("\nPress key to exit\n");
  scanw("%c",&input);

  nodelay(stdscr, TRUE);
  noecho();
  clear();
  delwin(w);

  return EXIT_SUCCESS;
}
