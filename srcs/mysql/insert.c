#include "app.h"

int insertIP(ip_addr ip, MYSQL *conn){

  char request[4096] = "INSERT INTO IPS(bit1,bit2,bit3,bit4,mask) VALUES (";
  char strnum[20];

  sprintf(strnum, "%d", ip.addr[0]); // int to str
	strcat(request, strnum); // concatain on request
	strcat(request, ","); // add ","

  sprintf(strnum, "%d", ip.addr[1]); // int to str
	strcat(request, strnum); // concatain on request
	strcat(request, ","); // add ","

  sprintf(strnum, "%d", ip.addr[2]); // int to str
	strcat(request, strnum); // concatain on request
	strcat(request, ","); // add ","

  sprintf(strnum, "%d", ip.addr[3]); // int to str
	strcat(request, strnum); // concatain on request
	strcat(request, ","); // add ","

	sprintf(strnum, "%d", ip.mask); // int to str
	strcat(request, strnum); // concatain on request

	strcat(request, ");"); // close sql request

	if (mysql_query(conn, request )) { // do request
    // if function return != 0: error
		fprintf(stderr, "%s\n", mysql_error(conn)); // print error message
    	return EXIT_FAILURE;
  }

	printf("Successfully insert\n");
	return EXIT_SUCCESS;
}
