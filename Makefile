CC = cc

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L ~/.brew/opt/readline/lib
CPPFLAGS = -I ~/.brew/opt/readline/include

SRCS = main.c init.c string.c linkedlist.c utils.c parser.c print.c

OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline -lncurses $(LDFLAGS) $(OBJS)  $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
