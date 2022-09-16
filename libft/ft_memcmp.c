/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:30:22 by junekim           #+#    #+#             */
/*   Updated: 2022/01/19 00:01:29 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)ptr1;
	tmp2 = (unsigned char *)ptr2;
	while (num--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		else
		{
			tmp1++;
			tmp2++;
			continue ;
		}
	}
	return (0);
}
