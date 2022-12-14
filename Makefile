NAME = app
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

INCLUDES = includes

SRCS = 	srcs/main.c				\
	srcs/mysql/insert.c		\
	srcs/mysql/select.c		\
	srcs/mysql/delete.c		\

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
