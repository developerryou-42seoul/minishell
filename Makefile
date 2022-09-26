NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

LIBFT = ./Libft
LIBFT_LIB = ft
READLINE = ~/.brew/opt/readline/include
READLINE_LIB = ~/.brew/opt/readline/lib

SRCS = main.c \
		init.c \
		quotes.c \
		string.c \
		linkedlist.c \
		utils.c \
		parser.c \
		redir.c \
		print.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		excute.c \
		path.c \
		stdinout.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT)/
	$(CC) $(CFLAGS) -L $(READLINE_LIB) -lreadline -lncurses  -L $(LIBFT) -l$(LIBFT_LIB) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(READLINE) -c $< -o $@

all : $(NAME)

clean :
	make fclean -C $(LIBFT)/
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
