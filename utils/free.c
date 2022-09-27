#include "minishell.h"

void	free_list(t_list *list)
{
	free(list);
}

void	free_block(t_block *block)
{
	free_list(block->argv);
	free_list(block->redir);
	free(block);
}

void	free_info(t_block_info *info)
{
	t_block	*temp_block;

	temp_block = info->head;
	while (info->head)
	{
		info->head = info->head->next;
		free(temp_block);
		temp_block = info->head;
	}
}