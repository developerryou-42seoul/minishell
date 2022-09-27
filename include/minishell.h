/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:32:32 by junekim           #+#    #+#             */
/*   Updated: 2022/09/27 16:46:02 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <stdlib.h>
# include <termcap.h>
# include <sys/termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "get_next_line.h"
# include "libft.h"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_redir
{
	int		type;
	char	*string;
}	t_redir;

typedef struct s_block
{
	int				argc;
	char			*path;
	t_list			*argv;
	int				quote[2];
	int				dollar;
	t_list			*redir;
	int				pipe_fd[2];
	t_list			*list_stdin;
	t_list			*list_stdout;
	struct s_block	*prev;
	struct s_block	*next;
}	t_block;

typedef struct s_block_info
{
	t_block	*head;
	t_block	*tail;
}	t_block_info;

typedef struct s_data
{
	int		past_return;
	char	**envp;
}	t_data;

t_data data;

void	init_g_data(char **envp);
int		init_terminal(struct termios *t);
void	init_block(t_block *block);

void	error(char *str);
char	**list_to_charptrptr(t_list *list);

int		parser(char *line, t_block_info *info);

void	add_block(t_block_info *info, t_block *block);
void	add_stdin(t_block *block, int fd);
void	add_stdout(t_block *block, int fd);
void	add_argv(t_block *block, char *str);
void	add_redir(t_block *block, int type, char *str);

void	create_empty(char **str);
int		is_space(t_block *block, char ch);
char	*mini_join(char *str, char ch);
char	*mini_join_str(char *s1, char *s2);

void	print_info(t_block_info *info);
void	print_block(t_block *block);

int		is_in_quote(t_block *block);
int		quote(t_block *block, char ch);

int		is_redir(t_block *block, char *line);

void	excute(t_block_info *info);

char	*find_exec(char *exec);

void	pipe_init(t_block_info *info);
void	pipe_restore(t_block_info *info);

void    stdin_manage(int fd_stdin, t_list *list_stdin);
void    stdout_manage(int fd_stdout, t_list *list_stdout);

char	*find_env(char *env, char **envp);

void	free_list(t_list *list);
void	free_block(t_block *block);
void	free_info(t_block_info *info);

#endif
