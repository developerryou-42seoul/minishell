/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 07:07:41 by junekim           #+#    #+#             */
/*   Updated: 2022/01/18 23:59:03 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (dest > src)
		while (num--)
			((unsigned char *)dest)[num] = ((unsigned char *)src)[num];
	else if (dest < src)
	{
		while (num--)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
