NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = ./include
AR = ar rcs
RM = rm -rf

LIBFT = ./Libft
LIBFT_LIB = ft
READLINE = ~/.brew/opt/readline/include
READLINE_LIB = ~/.brew/opt/readline/lib

SRCS = main.c \
		print.c \
		parse/quotes.c \
		parse/parser.c \
		parse/expand.c \
		parse/read_block.c \
		parse/change_dollar.c \
		excute/excute.c \
		excute/process.c \
		excute/path.c \
		excute/stdinout.c \
		utils/init.c \
		utils/string.c \
		utils/string2.c \
		utils/sll.c \
		utils/dll.c \
		utils/dic.c \
		utils/utils.c \
		utils/free.c \
		utils/signal.c \
		utils/error.c \
		utils/error2.c \
		builtins/builtins.c \
		builtins/builtin_export.c \
		builtins/builtin_pwd.c \
		builtins/builtin_cd.c \
		builtins/builtin_env.c \
		builtins/builtin_echo.c \
		builtins/builtin_exit.c \
		builtins/builtin_unset.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT)/
	$(CC) $(CFLAGS) -L $(READLINE_LIB) -lreadline -lncurses  -L $(LIBFT) -l$(LIBFT_LIB) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(READLINE) -I $(INCLUDE) -c $< -o $@

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
