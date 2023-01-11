#include "app.h"

void hexaIP(ip_addr ip) {

  int count=0;  // "count" helps to put "." when printing the IP address in the correct place
  int tmp=0;    // Keeps parts of the IP address we want to convert to hexadecimal form
  char hexaddr[4][2]={{0,0},{0,0},{0,0},{0,0}}; //Stores the final result; the hexadecimal form if the IP address

  // === hexadecimal conversion algorithm ===
  for(int j=3;j>=0;j--){
    tmp = ip.addr[j];
    for(int z=1;tmp>0;z--){
      hexaddr[j][z] = tmp % 16;
      tmp /= 16;
    }
  }

  // === Printing IP in XX.XX.XX.XX format ===
  for (int j = 0; j <4; j++){
    for(int z=0; z<2; z++){
      count++;
      if(count == 3){
        // printf(".");
        printw(".");
        count=1;
      }

      // printf("%x", hexaddr[j][z]);
      printw("%x", hexaddr[j][z]);
    }
  }

  // === For aesthetic purposes ===
  // printf("\n");
}
