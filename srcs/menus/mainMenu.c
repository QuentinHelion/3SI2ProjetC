#include "app.h"

int mainMenu(){
  short choice = 0;
  // char *str;

  do {
    // printf("%s",THEME_BAR_TOP);
    // printf("1: Show all saved IP\n");
    // printf("2: Add IP\n");
    // printf("3: Convert IP\n");
    // printf("4: Filter saved IP with mask\n");
    // printf("5: Delete saved IP\n");
    // printf("0: Exit\n");
    // printf("What do you want to do ?\n");

    initscr();              // Initialise la structure WINDOW et autres paramètres
    printw("%s",THEME_BAR_TOP);
    printw("1: Show all saved IP\n");
    printw("2: Add IP\n");
    printw("3: Convert IP\n");
    printw("4: Filter saved IP with mask\n");
    printw("5: Delete saved IP\n");
    printw("0: Exit\n");
    // endwin();
    // printw("What do you want to do ?\n");
    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    // getchstr(str);                // On attend que l'utilisateur appui sur une touche pour quitter

    scanw("%hd",&choice);
    // fgetc(stdin);
    // choice = strToInt(str);
  } while(choice > 5|| choice < 0);

  clear();
  // endwin();               // Restaure les paramètres par défaut du terminal
  return choice;
}
