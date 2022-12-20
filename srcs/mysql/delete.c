#include "app.h"

int deleteIP(char *id, MYSQL *conn){

	char request[4096] = "DELETE FROM IPS WHERE id = ";
	strcat(request, id); // concatain request & id

	if (mysql_query(conn, request )) { // do request
		// if function return != 0: error 
		fprintf(stderr, "%s\n", mysql_error(conn)); // print error message
		return EXIT_FAILURE;
	}

	printf("Successfully delete\n");
	return EXIT_SUCCESS;
}
