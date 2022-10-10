/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:34:30 by junekim           #+#    #+#             */
/*   Updated: 2022/10/11 02:45:32 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_numeric(t_block *block)
{
	char	*str;

	str = block->argv->next->content;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	check_longlong(long long sign, unsigned long long res, \
					int count)
{
	if (count > 19)
		return (1);
	if (sign == 1 && res > 9223372036854775807L)
		return (1);
	else if (sign == -1 && res > 9223372036854775808ULL)
		return (1);
	return (0);
}

int	check_atol(const char *str)
{
	unsigned long long	res;
	long long			sign;
	int					count;

	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	count = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		count++;
	}
	if (check_longlong(sign, res, count))
		return (0);
	return (1);
}

long long	ft_atol(const char *str)
{
	unsigned long long	res;
	long long			sign;
	int					count;

	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	count = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		count++;
	}
	if (check_longlong(sign, res, count))
		return (255);
	return (res * sign);
}
