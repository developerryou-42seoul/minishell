#include "minishell.h"

int	builtin_echo(t_block *block)
{
	t_list	*temp_list;
	int		flag;

	flag = 0;
	temp_list = block->argv->next;
	if (!(ft_strncmp(temp_list->content, "-n", 2)))
	{
		temp_list = temp_list->next;
		flag = 1;
	}
	while (temp_list)
	{
		printf("%s", temp_list->content);
		if (temp_list->next)
			printf(" ");
		temp_list = temp_list->next;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}