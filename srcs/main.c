# include "app.h"

int main(){

	// ======= PARTIE SQL =======

	MYSQL *conn;

	conn = mysql_init(NULL);

	printf("starting...\n");

	if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DB, 0, NULL, 0)) {
		printf("error: %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	} else {
		printf("Connection success\n");
	}


	ip_addr ipTest;

	ipTest.addr[0] = 192;
	ipTest.addr[1] = 168;
	ipTest.addr[2] = 0;
	ipTest.addr[3] = 1;
	ipTest.mask = 24;

	insertIP(ipTest,conn);

	char *column = "1";
	char *value = "1";

	selectIP(column, value, conn);

	//deleteIP("10", conn);

  mysql_close(conn);
	return EXIT_SUCCESS;
}
