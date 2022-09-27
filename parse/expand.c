#include "minishell.h"

char	*find_env(char *env, char **envp)
{
	char *temp_env;
	create_empty(&temp_env);
	temp_env = mini_join_str(temp_env, ++env);
	temp_env = mini_join(temp_env, '=');

	while (*envp)
	{
		if (!(ft_strncmp(temp_env, *envp, ft_strlen(temp_env))))
			return (*envp + ft_strlen(temp_env));
		envp++;
	}
	free(temp_env);
	return ("");
}
