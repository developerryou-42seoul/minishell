/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:16:31 by sryou             #+#    #+#             */
/*   Updated: 2022/10/11 02:42:59 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dic	*make_dic(char *key, char *value)
{
	t_dic	*new_dic;

	new_dic = malloc(sizeof(t_dic));
	if (new_dic == 0)
		return (0);
	new_dic->key = key;
	new_dic->value = value;
	return (new_dic);
}

char	*dic_to_charptr(t_dic *dic)
{
	char	*temp;
	char	*ret;

	temp = ft_strdup(dic->key);
	temp = mini_join(temp, '=');
	ret = ft_strjoin(temp, dic->value);
	free(temp);
	return (ret);
}

char	*split_key(char *env)
{
	char	*ret;
	size_t	idx;

	idx = 0;
	while (env[idx] != '=' && env[idx] != '\0')
		idx++;
	if (ft_strlen(env) == idx)
		return (0);
	ret = malloc(sizeof(char) * (idx + 1));
	ft_strlcpy(ret, env, idx + 1);
	return (ret);
}

char	*split_value(char *env)
{
	char	*ret;
	size_t	idx;

	idx = 0;
	while (env[idx] != '=' && env[idx] != '\0')
		idx++;
	if (idx == 0)
		error("not a valid identifier");
	if (ft_strlen(env) == idx)
		return (0);
	ret = malloc(sizeof(char) * (ft_strlen(env) - idx));
	ft_strlcpy(ret, env + idx + 1, ft_strlen(env) - idx);
	return (ret);
}
