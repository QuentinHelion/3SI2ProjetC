#include "app.h"

int deleteIP(char *id, MYSQL *conn){

	char request[4096] = "DELETE FROM IPS WHERE id = ";
	strcat(request, id);

	if (mysql_query(conn, request )) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		return EXIT_FAILURE;
	}

	printf("Succefuly delete\n");
	return EXIT_SUCCESS;
}
