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
			case 2: insertIpMenu(conn); break;
			case 3: convertMenu(); break;
			case 4: maskMenu(conn); break;
		}
	} while(app);

  mysql_close(conn);
	return EXIT_SUCCESS;
}
