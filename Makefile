CC = cc

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

#LDFLAGS = -L ~/.brew/opt/readline/lib
#CPPFLAGS = -I ~/.brew/opt/readline/include

LDFLAGS = -L/opt/homebrew/Cellar/readline/8.1.2/lib
CPPFLAGS = -I/opt/homebrew/Cellar/readline/8.1.2/include

SRCS = main.c init.c quotes.c string.c linkedlist.c utils.c parser.c redir.c print.c

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