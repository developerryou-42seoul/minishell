#include "minishell.h"

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;
	
	i = 0;
	while (i < len && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*find_env(char *env, char **envp)
{
	char *temp_env;
	create_empty(&temp_env);
	temp_env = mini_join_str(temp_env, ++env);
	temp_env = mini_join(temp_env, '=');

	while (*envp)
	{
		if ((ft_strncmp(temp_env, *envp, ft_strlen(temp_env))))
			return (*envp + ft_strlen(temp_env));
		envp++;
	}
	free(temp_env);
	return ("no envp");
}
