#include "app.h"

int insertIP(ip_addr ip, MYSQL *conn){

  MYSQL_RES *res;

  char request[4096] = "INSERT INTO IPS(bit1,bit2,bit3,bit4,mask) VALUES (";
  char strnum[20];

  sprintf(strnum, "%d", ip.addr[0]);
	strcat(request, strnum);
	strcat(request, ",");

  sprintf(strnum, "%d", ip.addr[1]);
	strcat(request, strnum);
	strcat(request, ",");

  sprintf(strnum, "%d", ip.addr[2]);
	strcat(request, strnum);
	strcat(request, ",");

  sprintf(strnum, "%d", ip.addr[3]);
	strcat(request, strnum);
	strcat(request, ",");

	sprintf(strnum, "%d", ip.mask);
	strcat(request, strnum);

	strcat(request, ");");


	printf("request: %s\n", request);

	if (mysql_query(conn, request )) {
		fprintf(stderr, "%s\n", mysql_error(conn));
    	return EXIT_FAILURE;
  	}

	res = mysql_use_result(conn);
	mysql_free_result(res);

	printf("Successfully insert\n");
	return EXIT_SUCCESS;
}
