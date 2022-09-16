/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:20:02 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 17:59:36 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

static int	is_not_overflow(long long digit, int neg, const char *nptr)
{
	if (neg == 1)
	{
		if (digit < -922337203685477580 && ft_isdigit(*nptr))
			return (0);
		else if (digit == -922337203685477580 && *nptr == '9')
			return (0);
	}
	else
	{
		if (digit > 922337203685477580 && ft_isdigit(*nptr))
			return (-1);
		else if (digit == 922337203685477580 && '8' <= *nptr && *nptr <= '9')
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	digit;
	int			neg;
	int			i;

	digit = 0;
	i = 0;
	neg = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			neg = 1;
	while (ft_isdigit(nptr[i]))
	{
		digit *= 10;
		if (neg == 1)
			digit -= (nptr[(i)++] - '0');
		else
			digit += (nptr[(i)++] - '0');
		if (is_not_overflow(digit, neg, &nptr[i]) != 1)
			return (is_not_overflow(digit, neg, &nptr[i]));
	}
	return ((int)digit);
}
