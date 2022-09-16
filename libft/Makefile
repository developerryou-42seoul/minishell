# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <june1171@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 13:00:54 by junekim           #+#    #+#              #
#    Updated: 2022/08/08 17:23:45 by junekim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_strncmp.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strrchr.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:%.c=%.o)

BOBJS = $(BSRCS:%.c=%.o)


ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(BOBJS)
else
	OBJECTS = $(OBJS)
endif

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	arch -x86_64 $(AR) $@ $^

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	arch -x86_64 $(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re .c.o