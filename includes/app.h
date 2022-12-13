#ifndef APP_H
# define APP_H


// === Includes ===

# include <stdlib.h>
# include <stdio.h>
# include <mysql/mysql.h>
# include <string.h>


// === Variables ===

# define SERVER   "localhost"
# define USER     "root"
# define PASSWORD "root"
# define DB       "2SI2ProjetC"


// === Structures ===

typedef struct IPaddr{
	int addr[4];
	int mask;
} ip_addr;


// === Prototypes ===

int insertIP(ip_addr ip, MYSQL *conn);
int selectWhere(char *column, char *value, MYSQL *conn);


#endif
