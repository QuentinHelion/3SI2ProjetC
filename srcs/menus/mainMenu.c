#include "app.h"

int mainMenu(){
  short choice = 0;

  do {
    printf("\n========oOo========\n");
    printf("1: Show all saved IP\n");
    printf("2: Add IP\n");
    printf("3: Convert IP\n");
    printf("0: Quitter\n");
    printf("Que voulez-vous faire ?\n");

    scanf("%hd",&choice);
    fgetc(stdin);
  } while(choice > 3 || choice < 0);

  return choice;
}
