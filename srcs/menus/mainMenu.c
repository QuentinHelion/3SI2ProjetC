#include "app.h"

int mainMenu(){
  short choice = 0;
  //char* choiceStr;

  do {
    printf("\n========oOo========\n");
    printf("1: Add IP\n");
    printf("2: Show all saved IP\n");
    printf("0: Quitter\n");
    printf("Que voulez-vous faire ?\n");

    scanf("%hd",&choice);
    //choice = intToStr(choiceStr)
  } while(choice > 2 || choice < 0);

  return choice;
}
