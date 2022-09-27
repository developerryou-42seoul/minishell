/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:34:30 by junekim           #+#    #+#             */
/*   Updated: 2022/09/27 16:34:42 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *str)
{
	printf("%s ", str);
	printf("error\n");
	exit(1);
}

char	**list_to_charptrptr(t_list *list)
{
	char	**ret;
	int		len;
	int		idx;

	len = ft_lstsize(list);
	ret = malloc(sizeof(char **) * (len + 1));
	if (ret == 0)
		error(strerror(errno));
	idx = 0;
	while (idx < len)
	{
		ret[idx] = (char *)list->content;
		list = list->next;
		idx ++;
	}
	ret[idx] = 0;
	return (ret);
}