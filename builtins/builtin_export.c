#include "minishell.h"

int	find_length_envp()
{
	int	idx;

	idx = 0;
	while(data->envp[idx] != 0)
		idx++;
	return (idx);
}

int	is_correct_argv(char *content)
{
	(void)content;
	return (1);
}

int	find_length_correct_argv(t_list *argv)
{
	int	len;

	len = 0;
	while (argv)
	{
		if (is_correct_argv(argv->content))
			len++;
		argv = argv->next;
	}
	return (len);
}

void	copy_envp(char **new_envp, int len_envp)
{
	int	idx;

	idx = 0;
	while (idx < len_envp)
	{
		new_envp[idx] = data->envp[idx];
		idx++;
	}
}

void	copy_argv(char **new_envp, t_list *argv, int len_argv)
{
	int	idx;

	idx = 0;
	while (idx < len_argv)
	{
		if (is_correct_argv(argv->content))
			new_envp[idx] = argv->content;
		idx++;
	}
}

int	print_envp(int len_envp)
{
	int	idx;

	idx = 0;
	while (idx < len_envp)
	{
		printf("%s\n", data->envp[idx]);
		idx++;
	}
	return (0);
}

int	builtin_export(t_block *block)
{
	char	**new_envp;
	int		len_envp;
	int		len_argv;

	len_envp = find_length_envp();
	//return (print_envp(len_envp));
	len_argv = find_length_correct_argv(block->argv);
	new_envp = malloc(sizeof(char *) * (len_argv + len_envp + 1));
	if (new_envp == 0)
		return (errno);
	copy_envp(new_envp, len_envp);
	copy_argv(new_envp + len_envp, block->argv, len_argv);
	new_envp[len_argv + len_envp] = 0;
	//free(data->envp);
	data->envp = new_envp;
	return (0);
}