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
				srcs/tools/checkIpValid.c		\
				srcs/tools/checkMaskValid.c	\
				srcs/tools/strToInt.c				\
				srcs/tools/ipToStruct.c			\

OBJS = $(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) -lmysqlclient

$(OBJS): $(INCLUDES)/app.h

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS) -lmysqlclient

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
