/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:34:30 by junekim           #+#    #+#             */
/*   Updated: 2022/09/20 17:10:44 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar(int ch)
{
	if (write(STDOUT_FILENO, &ch, sizeof(ch)) < 0)
		return (1);
	return (0);
}

void	error(char *str)
{
	printf("%s ", str);
	printf("error\n");
	exit(1);
}
