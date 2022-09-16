/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:11:26 by junekim           #+#    #+#             */
/*   Updated: 2021/12/30 11:28:25 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
