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

void	check_longlong(long long sign, unsigned long long res, \
					const char *str, int count)
{
	if (count > 19)
	{
		printf("mini: exit: %s: numeric argument required\n", str);
		exit(255);
	}	
	if (sign == 1 && res > 9223372036854775807L)
	{
		printf("mini: exit: %s: numeric argument required\n", str);
		exit(255);
	}
	else if (sign == -1 && res > 9223372036854775808ULL)
	{
		printf("mini: exit: %s: numeric argument required\n", str);
		exit(255);
	}
}

long long	ft_atol(const char *str)
{
	unsigned long long	res;
	long long			sign;
	int					count;

	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	count = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		count++;
	}
	check_longlong(sign, res, str, count);
	return (res * sign);
}

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
