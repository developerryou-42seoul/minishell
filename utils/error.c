/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:31:17 by jnam              #+#    #+#             */
/*   Updated: 2022/10/04 21:31:19 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *str)
{
	printf("%s ", str);
	exit(1);
}

int	error_export(char *str, char *key)
{
	printf("mini: export: '%s': %s\n", key, str);
	return (1);
}

int	error_cnf(char *str, char *exec)
{	
	printf("mini: %s: %s\n", exec, str);
	exit(127);
}

int	error_cd(char *str, char *name)
{
	printf("mini: cd: %s: %s\n", name, str);
	return (2);
}
