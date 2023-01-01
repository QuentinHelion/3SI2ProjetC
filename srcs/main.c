# include "app.h"

int main(){

	// ======= VARIABLES ==========
	int app;
	MYSQL *conn;

	// ======= SQL CONNECTION =======
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DB, 0, NULL, 0)) {
		printf("error: %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	} else {
		// printf("Connection success\n");
	}

 // ======= APP PART =======
	do {
		app = mainMenu(); // call main menu & stock user choice
		switch (app) {
			case 1: selectMenu(conn); break; // show all saved IPS
			case 2: insertIpMenu(conn); break; // db IP insertion
			case 3: convertMenu(); break; // IP convertion (bin, hex, type)
			case 4: maskMenu(conn); break; // show save IPS with specific mask
			case 5: deleteIpMenu(conn); break; // delete IP
		}
	} while(app); // when choice == 2 app stop

  mysql_close(conn); // Close mysql connection
	endwin();
	return EXIT_SUCCESS;
}
