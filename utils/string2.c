/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:55:56 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 20:03:01 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_same_str(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2) && \
	ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
