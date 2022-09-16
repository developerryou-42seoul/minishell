/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 06:44:25 by junekim           #+#    #+#             */
/*   Updated: 2022/01/14 22:28:35 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t num)
{
	unsigned char	*buf;

	buf = (unsigned char *) ptr;
	while (num--)
		*buf++ = 0;
	return (ptr);
}
