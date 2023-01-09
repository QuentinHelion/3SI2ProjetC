#ifndef APP_H
# define APP_H


// === Includes ===

# include <stdlib.h>
# include <stdio.h>
# include <mysql/mysql.h>
# include <string.h>
# include <ncurses.h>


// === Constants ===
// == DB credential ==
# define SERVER   			"localhost"
# define USER     			"root"
# define PASSWORD 			"root"
# define DB       			"2SI2ProjetC"

// == Other ==
# define MAX_MASK_VALUE 32
# define MIN_MASK_VALUE 1
# define THEME_BAR_TOP 	"\n========oOo========\n"


// === Structures ===

typedef struct IPaddr{
	int addr[4];
	int mask;
} ip_addr;


// === Prototypes ===
// == Menus ==
int mainMenu();
int convertMenu();
int insertIpMenu(MYSQL *conn);
int maskMenu(MYSQL *conn);
int deleteIpMenu(MYSQL *conn);
int selectMenu(MYSQL *conn);
int exitMenu();
int logo();

// == SQL ==
int insertIP(ip_addr ip, MYSQL *conn);
int selectIP(char *column, char *value, MYSQL *conn);
int deleteIP(char *id, MYSQL *conn);
int filterMask(char *value, MYSQL *conn);

// == Converters ==
void binaryIP(ip_addr ip);
void hexaIP(ip_addr ip);
int ipType(ip_addr ip);

// == Tools ==
int strToInt(char *value);
int checkMaskValid(char *mask);
int checkIpValid(char *ip);
ip_addr ipToStruct(char *ip, char *mask);

#endif
