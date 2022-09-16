/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:16:39 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 17:59:58 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_malloc(int n, int *i)
{
	int		size;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	*i += size;
	str = (char *)malloc(sizeof(char) * (*i + 1));
	if (!str)
		return (NULL);
	if (str)
		str[(*i)--] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		i;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	i = neg ;
	str = itoa_malloc(n, &i);
	if (!str)
		return (NULL);
	while (n)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == 1)
		str[i] = '-';
	return (str);
}
