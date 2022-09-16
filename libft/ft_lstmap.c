/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:27:34 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 17:05:43 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*maplist;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	maplist = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&maplist, del);
			return (NULL);
		}
		ft_lstadd_back(&maplist, tmp);
		lst = lst -> next;
	}
	return (maplist);
}
