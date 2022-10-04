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
