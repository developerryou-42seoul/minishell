/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:27:25 by junekim           #+#    #+#             */
/*   Updated: 2022/01/16 17:12:46 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = tmp -> next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
}
