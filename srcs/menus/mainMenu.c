#include "app.h"

int mainMenu(){
  short choice = 0;

  do {
    printf("%s",THEME_BAR_TOP);
    printf("1: Show all saved IP\n");
    printf("2: Add IP\n");
    printf("3: Convert IP\n");
    printf("4: Filter saved IP with mask\n");
    printf("5: Delete saved IP\n");
    printf("0: Exit\n");
    printf("What do you want to do ?\n");

    scanf("%hd",&choice);
    fgetc(stdin);
  } while(choice > 5|| choice < 0);

  return choice;
}
