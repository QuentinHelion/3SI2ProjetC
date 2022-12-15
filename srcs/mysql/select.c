#include "app.h"

// SELECT CONCAT(bit1,'.',bit2,'.',bit3,'.',bit4), maskFROM IPS;

int selectIP(char *column, char *value, MYSQL *conn){

  MYSQL_RES *res;
  MYSQL_ROW row;

  char request[512] = "SELECT id, CONCAT(bit1,'.',bit2,'.',bit3,'.',bit4), mask FROM IPS WHERE ";
  strcat(request, column);
  strcat(request, " = ");
  strcat(request, value);

  if (mysql_query(conn, request)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return EXIT_FAILURE;
  }

  res = mysql_use_result(conn);

  printf(" ID | IP          | MASK\n");

  while((row = mysql_fetch_row(res)) != NULL)
    printf(" %s  | %s | %s   \n", row[0],row[1], row[2]);

  mysql_free_result(res);
	return EXIT_SUCCESS;
}
