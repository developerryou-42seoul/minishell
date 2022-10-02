/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:55:15 by junekim           #+#    #+#             */
/*   Updated: 2022/10/03 01:42:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_stdin(t_block *block, int fd)
{
	int	*fd_ptr;

	fd_ptr = malloc(sizeof(int));
	if (fd_ptr == 0)
		error(strerror(errno));
	*fd_ptr = fd;
	ft_lstadd_back(&(block->list_stdin), ft_lstnew(fd_ptr));
}

void	add_stdout(t_block *block, int fd)
{
	int	*fd_ptr;

	fd_ptr = malloc(sizeof(int));
	if (fd_ptr == 0)
		error(strerror(errno));
	*fd_ptr = fd;
	ft_lstadd_back(&(block->list_stdout), ft_lstnew(fd_ptr));
}

void	add_argv(t_block *block, char *str)
{
	ft_lstadd_back(&(block->argv), ft_lstnew(str));
	block->argc += 1;
}

void	add_redir(t_block *block, int type, char *str)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->type = type;
	redir->string = str;
	ft_lstadd_back(&(block->redir), ft_lstnew(redir));
}

void	add_envp(char *key, char *value)
{
	t_dic *dic;

	dic = make_dic(key, value);
	ft_lstadd_back(&(g_data->envp), ft_lstnew(dic));
}
