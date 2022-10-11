/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:31:17 by jnam              #+#    #+#             */
/*   Updated: 2022/10/11 14:15:01 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *str)
{
	ft_putstr_fd("mini: ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	error_export(char *str, char *key)
{
	ft_putstr_fd("mini: export: ", 2);
	ft_putstr_fd(key, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	error_cnf(char *str, char *exec)
{	
	ft_putstr_fd("mini: ", 2);
	ft_putstr_fd(exec, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

int	error_cd(char *str, char *name)
{
	ft_putstr_fd("mini: cd: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	error_unset(char *str, char *arg)
{
	ft_putstr_fd("mini: unset: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
