/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:50:58 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 18:00:33 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_size_function(char *s, char c)
{
	int		split_size;
	int		i;

	if (!*s)
		return (0);
	split_size = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{	
		while (s[i] == c)
			i++;
		if (s[i])
			split_size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (split_size);
}

static char	*str_malloc(char *s, char c)
{
	int		len;
	char	*arr;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s, len + 1);
	return (arr);
}

static char	**split_free(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i++]);
	}
	free(split);
	return (NULL);
}

static void	var_allocate(int split_size, int *i, char ***split)
{
	*i = 0;
	*split = (char **)malloc(sizeof(char *) * (split_size + 1));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		split_size;
	int		i;

	if (!s)
		return (NULL);
	split_size = split_size_function((char *)s, c);
	var_allocate(split_size, &i, &split);
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			split[i] = str_malloc((char *)s, c);
			if (split[i++] == NULL)
				return (split_free(split));
		}
		while (*s != c && *s)
			s++;
	}
	split[i] = NULL;
	return (split);
}
