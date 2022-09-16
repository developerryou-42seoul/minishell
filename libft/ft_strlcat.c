/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:50:17 by junekim           #+#    #+#             */
/*   Updated: 2022/01/15 01:04:36 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = 0;
	while (src[j] && j + dest_len + 1 < size)
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	if (dest_len + 1 <= size)
	{
		dst[j + dest_len] = '\0';
		return (dest_len + src_len);
	}
	dest_len = size;
	return (src_len + dest_len);
}
