CC = cc

NAME = minishell

CFLAGS = -Wall -Werror -Wextra

READLINE = ~/.brew/opt/readline
#READLINE = 
#READLINE =
#READLINE = 

LDFLAGS = -L $(READLINE)/lib
CPPFLAGS = -I $(READLINE)/include

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
