#include "app.h"

void hexaIP(ip_addr ip) {

  int count=0;
  int tmp=0;
  char hexaddr[4][2]={{0,0},{0,0},{0,0},{0,0}};

  for(int j=3;j>=0;j--){
    tmp = ip.addr[j];
    for(int z=1;tmp>0;z--){
      hexaddr[j][z] = tmp % 16;
      tmp /= 16;
    }
  }
  for (int j = 0; j <4; j++){
    for(int z=0; z<2; z++){
      count++;
      if(count == 3){
        printf(".");
        count=1;
      }
      printf("%x", hexaddr[j][z]);
    }
  }

  printf("\n");
}
