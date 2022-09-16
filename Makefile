CC = cc

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L /opt/homebrew/Cellar/readline/8.1.2/lib
CPPFLAGS = -I /opt/homebrew/Cellar/readline/8.1.2/include

SRCS = main.c init.c cursor.c cursor_move.c minishell_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -lreadline -lncurses $(LDFLAGS) $(OBJS)  $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT) :
	make -C ./libft

clean:
	make clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
