/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:00:21 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 00:57:21 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	if (!str)
		return (NULL);
	i = 0;
	chr = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (NULL);
}
