/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:43:14 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:16:50 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;
	char	*tmp;

	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (*big && len >= len_little)
	{
		i = 0;
		len--;
		tmp = (char *)big;
		while (i < len_little)
		{
			if (*(big + i) != little[i])
				break ;
			i++;
		}
		if (i == len_little)
			return (tmp);
		big ++;
	}
	return (NULL);
}
