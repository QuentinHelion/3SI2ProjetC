#ifndef APP_H
# define APP_H


// === Includes ===

# include <stdlib.h>
# include <stdio.h>
# include <mysql/mysql.h>
# include <string.h>


// === Variables ===

# define SERVER   			"localhost"
# define USER     			"root"
# define PASSWORD 			"root"
# define DB       			"2SI2ProjetC"
# define MAX_MASK_VALUE 32
# define MIN_MASK_VALUE 1


// === Structures ===

typedef struct IPaddr{
	int addr[4];
	int mask;
} ip_addr;


// === Prototypes ===

int mainMenu();
int insertIP(ip_addr ip, MYSQL *conn);
int selectIP(char *column, char *value, MYSQL *conn);
int deleteIP(char *id, MYSQL *conn);
int filterMask(char *value, MYSQL *conn);
void binaryIP(ip_addr ip);
void hexaIP(ip_addr ip);
int ipType(ip_addr ip);
int checkIpValid(char *ip);
int insertIpMenu(MYSQL *conn);
int strToInt(char *value);
int checkMaskValid(char *mask);
int convertMenu();
ip_addr ipToStruct(char *ip, char *mask);

#endif
