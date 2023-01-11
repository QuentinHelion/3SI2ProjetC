# include "app.h"

int main(){

	// ======= VARIABLES ==========
	int app;
	int choice;
	MYSQL *conn;

	// ======= SQL CONNECTION =======
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DB, 0, NULL, 0)) {
		printf("error: %s\n", mysql_error(conn));
		return EXIT_FAILURE;
	} else {
		// printf("Connection success\n");
	}

	initscr(); // initialize Ncurses
	start_color(); // enable color on app
  init_pair(1, COLOR_WHITE, COLOR_BLACK); // create color (text + background)
  attron(COLOR_PAIR(1)); // set color

 // ======= APP PART =======
	do {
		app = mainMenu(); // call main menu & stock user choice
		refresh(); // refresh window
		switch (app) {
			case 1: choice = catalogMenu(); choice == 1 ? selectMenu(conn) : choice == 2 ? maskMenu(conn) : 0; break; // IP catalog
			case 2: insertIpMenu(conn); break; // db IP insertion
			case 3: convertMenu(); break; // IP convertion (bin, hex, type)
			case 4: deleteIpMenu(conn); break; // delete IP
		}
		refresh(); //refresh window
	} while(app != 5); // when choice == 2 app stop

  mysql_close(conn); // Close mysql connection
	endwin(); // close window

	return EXIT_SUCCESS;
}
