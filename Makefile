CC = cc

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L ~/.brew/opt/readline/lib
CPPFLAGS = -I ~/.brew/opt/readline/include

SRCS = main.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline $(LDFLAGS) $(OBJS) -o $(NAME)

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
