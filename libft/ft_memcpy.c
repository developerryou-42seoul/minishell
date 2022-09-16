/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 06:47:50 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 17:41:11 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (!dest)
		return (NULL);
	while (i < num)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
