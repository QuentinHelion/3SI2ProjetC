#include "app.h"

// SELECT CONCAT(bit1,'.',bit2,'.',bit3,'.',bit4), mask FROM IPS;

int selectIP(char *column, char *value, MYSQL *conn){

  MYSQL_RES *res;
  MYSQL_ROW row;

  char request[512] = "SELECT id, CONCAT(bit1,'.',bit2,'.',bit3,'.',bit4), mask FROM IPS WHERE ";
  strcat(request, column); // add column
  strcat(request, " = ");
  strcat(request, value); // add value

  if (mysql_query(conn, request )) { // do request
    // if function return != 0: error
		fprintf(stderr, "%s\n", mysql_error(conn)); // print error message
    	return EXIT_FAILURE;
  }

  res = mysql_use_result(conn); // stock result of query

  printw(" ID | IP          | MASK\n");

  while((row = mysql_fetch_row(res)) != NULL) // line to row
    printw(" %s  | %s | %s   \n", row[0],row[1], row[2]); // print row

  mysql_free_result(res); // clean mysql query
	return EXIT_SUCCESS;
}
