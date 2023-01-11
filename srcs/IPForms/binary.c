#include "app.h"

void binaryIP(ip_addr ip) {

  int count=0;  // "count" helps to put "." when printing the IP address in the correct place
  int tmp=0;    // Keeps parts of the IP address we want to convert to binary form
  int binaddr[4][8]={0};  // Stores the final result; the binary form of the IP address

  // === Binary conversion algorithm ===
  for(int j=3;j>=0;j--){
    tmp = ip.addr[j];
    for(int z=7;tmp>0;z--){
      binaddr[j][z] = tmp % 2;
      tmp /= 2;
    }
  }

  // === Printing IP in XXXXXXXX.XXXXXXXX.XXXXXXXX.XXXXXXXX format ===
  for (int j = 0; j <4; j++){
    for(int z=0; z<8; z++){
      count++;
      if(count == 9){
        // printf(".");
        printw(".");
        count=1;
      }

      // printf("%d", binaddr[j][z]);
      printw("%d", binaddr[j][z]);
    }
  }

  // === For aesthetic purposes ===
  // printf("\n");
}
