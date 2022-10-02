#include "minishell.h"

void	push_argv_to_envp(t_list *argv)
{
	char	*key;
	char	*value;
	while (argv)
	{
		key = split_key(argv->content);
		value = split_value(argv->content);
		if (key != 0 && value != 0)
			add_envp(key, value);
		argv = argv->next;
	}
}

int	builtin_export(t_block *block)
{
	//return (print_envp(len_envp));
	push_argv_to_envp(block->argv->next);
	return (0);
}