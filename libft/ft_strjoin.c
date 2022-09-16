/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:30:58 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:05:00 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + len_s2 + 1);
	ft_strlcat(ptr, s2, len_s1 + len_s2 + 1);
	return (ptr);
}
