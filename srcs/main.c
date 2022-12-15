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

	ipTest.addr[0] = 172;
	ipTest.addr[1] = 16;
	ipTest.addr[2] = 14;
	ipTest.addr[3] = 69;
	ipTest.mask = 22;

	// insertIP(ipTest,conn);

	// char *column = "1";
	//char *value = "22";

	//selectIP(column, value, conn);

	//deleteIP("3", conn);

	//filterMask(value,conn);
	ipType(ipTest);

	binaryIP(ipTest);
  mysql_close(conn);
	return EXIT_SUCCESS;
}
