NAME = app
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

INCLUDES = includes

SRCS = 	srcs/main.c									\
				srcs/filter.c								\
				srcs/ipType.c								\
				srcs/mysql/insert.c					\
				srcs/mysql/select.c					\
				srcs/mysql/delete.c					\
				srcs/IPForms/binary.c				\
			  srcs/IPForms/hexa.c					\
				srcs/menus/mainMenu.c				\
				srcs/menus/insertIpMenu.c		\
				srcs/menus/convertMenu.c		\
				srcs/menus/maskMenu.c				\
				srcs/menus/deleteIpMenu.c		\
				srcs/menus/selectMenu.c			\
				srcs/menus/catalogMenu.c		\
				srcs/tools/checkIpValid.c		\
				srcs/tools/checkMaskValid.c	\
				srcs/tools/strToInt.c				\
				srcs/tools/ipToStruct.c			\
				srcs/menus/includes/exit.c	\
				srcs/menus/includes/logo.c	\

OBJS = $(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) -lmysqlclient -lncurses

$(OBJS): $(INCLUDES)/app.h

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS) -lmysqlclient -lncurses

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
