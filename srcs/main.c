# include "app.h"

int main(){

	// ======= VARIABLES ==========
	int app;
	MYSQL *conn;

	// ======= SQL CONNECTION =======
	conn = mysql_init(NULL);
	//printf("starting...\n");
	if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DB, 0, NULL, 0)) {
		printf("error: %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	} else {
		// printf("Connection success\n");
	}

 // ======= APP PART =======
	do {
		app = mainMenu();
		switch (app) {
			case 1: selectIP("1", "1", conn); break;
			case 2: insertIpMenu(); break;
		}
		//app = app == 0 ? 0 : -1;
	} while(app);





	// ip_addr ipTest;
	//
	// ipTest.addr[0] = 172;
	// ipTest.addr[1] = 16;
	// ipTest.addr[2] = 14;
	// ipTest.addr[3] = 69;
	// ipTest.mask = 22;

	// insertIP(ipTest,conn);

	// char *column = "1";
	//char *value = "22";

	//selectIP(column, value, conn);

	//deleteIP("3", conn);

	// filterMask(value,conn);
	//hexaIP(ipTest);
	//ipType(ipTest);
	//binaryIP(ipTest);


  mysql_close(conn);
	return EXIT_SUCCESS;
}
