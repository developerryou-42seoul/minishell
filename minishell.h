/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:32:32 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 17:09:33 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_UP			4283163
# define KEY_DOWN		4348699
# define KEY_BACKSPACE	127

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <termcap.h>
# include <sys/termios.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	int				type;
	char			*string;
	struct s_list	*next;
}	t_list;

typedef struct s_block
{
	int				argc;
	t_list			*argv;
	int				quote[2];
	int				dollar;
	t_list			*redir;
	struct s_block	*prev;
	struct s_block	*next;
}	t_block;

typedef struct s_block_info
{
	t_block	*head;
	t_block	*tail;
}	t_block_info;

int		init_terminal(struct termios *t);
void	init_list(t_list *list);
void	init_block(t_block *block);

int		ft_putchar(int ch);
void	error(char *str);

int		parser(char *line, t_block_info *info);

void	add_block(t_block_info *info, t_block *block);
void	add_argv(t_block *block, char *str);
void	add_redir(t_block *block, int type, char *str);

int		ft_strlen(char *str);
void	create_empty(char **str);
int		is_space(t_block *block, char ch);
char	*mini_join(char *str, char ch);
char	*mini_join_str(char *s1, char *s2);
char	*ft_dup(char *str);

void	print_info(t_block_info *info);
void	print_block(t_block *block);

int		is_in_quote(t_block *block);
int		quote(t_block *block, char ch);

int		is_redir(t_block *block, char *line);

#endif
