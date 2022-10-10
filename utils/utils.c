/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:34:30 by junekim           #+#    #+#             */
/*   Updated: 2022/10/09 22:11:56 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**diclist_to_charptrptr(t_list *list)
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
		ret[idx] = dic_to_charptr(list->content);
		list = list->next;
		idx ++;
	}
	ret[idx] = 0;
	return (ret);
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

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
