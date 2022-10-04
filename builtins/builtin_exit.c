#include "minishell.h"

#include "minishell.h"

static int	check_numeric(t_block *block)
{
	char *str;

	str = block->argv->next->content;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	builtin_exit(t_block *block)
{
	if (block->argc > 2)
	{
		if (check_numeric(block))
		{
			printf("mini: exit: too many arguments\n");
			return (1); //종료되면 안됨, 수정필요
		}
		else 
			printf("mini: exit: %s: numeric argument required\n", \
					block->argv->next->content);
		exit(1);	
	}
	else if (block->argc == 2)
	{
		if (!check_numeric(block))
			printf("mini: exit: %s: numeric argument required\n", \
					block->argv->next->content);
		exit (1);
	}
	exit(0);
	return (0);
}