/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:44:44 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 18:01:02 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char const c, char const *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start + 1] && is_set(s1[start], set))
		start++;
	while (0 < end - 1 && is_set(s1[end - 1], set))
		end--;
	if ((end - start <= 0))
		return (ft_strdup(""));
	ptr = (char *)malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}
