#include "app.h"

void binaryIP(ip_addr ip) {

  int count=0;
  int tmp=0;
  int binaddr[4][8]={0};

  //Set all 2D array values to 0
  //memset(binaryIP.binaddr,0,sizeof(binaryIP.binaddr));

  for(int j=3;j>=0;j--){
    tmp = ip.addr[j];
    //printf("tmp = %d\n",tmp);
    for(int z=7;tmp>0;z--){
      binaddr[j][z] = tmp % 2;
      tmp /= 2;
    }
  }

  for (int j = 0; j <4; j++){
    for(int z=0; z<8; z++){
      count++;
      if(count == 9){
        printf(".");
        count=1;
      }

      printf("%d", binaddr[j][z]);
    }
  }

  printf("\n");
}
