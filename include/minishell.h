/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:32:32 by junekim           #+#    #+#             */
/*   Updated: 2022/10/06 15:53:49 by junekim          ###   ########seoul.kr  */
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

typedef struct s_dic
{
	char	*key;
	char	*value;
}	t_dic;

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
	int				past_return;
	t_list			*envp;
	struct termios	t;
}	t_data;

t_data	*g_data;

void	init_g_data(char **envp);
void	init_block(t_block *block);

void	error(char *str);
int		error_cnf(char *str, char *exec);
int		error_cd(char *str, char *name);
int		error_export(char *str, char *key);
int		error_unset(char *str, char *arg);

int		error_env(char *str, char *arg);

char	**list_to_charptrptr(t_list *list);
char	**diclist_to_charptrptr(t_list *list);

int		parser(char *line, t_block_info *info);

void	add_block(t_block_info *info, t_block *block);
void	add_stdin(t_block *block, int fd);
void	add_stdout(t_block *block, int fd);
void	add_argv(t_block *block, char *str);
void	add_redir(t_block *block, int type, char *str);
void	add_envp(char *key, char *value);

t_dic	*make_dic(char *key, char *value);
char	*dic_to_charptr(t_dic *dic);
char	*split_key(char *env);
char	*split_value(char *env);

char	*mini_join(char *str, char ch);
char	*mini_join_str(char *s1, char *s2);
void	create_empty(char **str);

void	read_block(char **line, t_block_info *info);

void	print_info(t_block_info *info);
void	print_block(t_block *block);

int		quote(t_block *block, char ch);
int		is_in_quote(t_block *block);

int		is_space(t_block *block, char ch);
int		is_end(t_block *block, char ch);
int		is_same_str(char *s1, char *s2);
int		is_redir(t_block *block, char *line);
int		is_esr(t_block *block, char **line);

void	excute(t_block_info *info);
void	runprocess(t_block *block);

int		check_builtins_before_fork(t_block *block);
int		excute_builtins_before_fork(t_block *block);
int		check_builtins_after_fork(t_block *block);
int		excute_builtins_after_fork(t_block *block);

int		builtin_echo(t_block *block);
int		builtin_cd(t_block *block);
int		builtin_pwd(t_block *block);
int		builtin_unset(t_block *block);
int		push_argv_to_envp(t_list *argv);
int		builtin_export(t_block *block);
int		builtin_env(t_block *block);
void	print_envp(t_list *envp);
int		builtin_exit(t_block *block);
int		check_exit(t_block *block);

char	*find_exec(char *exec);

void	pipe_init(t_block_info *info);
void	pipe_restore(t_block_info *info);

void	stdin_manage(int fd_stdin, t_list *list_stdin);
void	stdout_manage(int fd_stdout, t_list *list_stdout);

char	*find_env(char *env, t_list *envp, int flag);
int		change_env(t_list *envp, char *key, char *value);

void	free_info(t_block_info *info);

void	parent_signal(int signum);
void	child_signal(int signum);
void	set_signal(void);
void	set_terminal(struct termios *t);
void	reset_terminal(struct termios *t);

char	*change_dollar(char *line);

#endif
