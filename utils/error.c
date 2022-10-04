#include "minishell.h"

void	error(char *str)
{
	printf("%s ", str);
	exit(1);
}

int	error_export(char *str, char *key)
{
	printf("mini: export: '%s': %s\n", key, str);
	return (1);
}

int	error_cnf(char *str, char *exec)
{	
	printf("mini: %s: %s\n", exec, str);
	return (127);
}

int	error_cd(char *str, char *name)
{
	printf("mini: cd: %s: %s\n", name, str);
	return (2);
}
