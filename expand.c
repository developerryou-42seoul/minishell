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
	char *a;
	create_empty(&a);
	a = mini_join_str(a, ++env);
	a = mini_join(a, '=');

	while (*envp)
	{
		if ((ft_strncmp(a, *envp, ft_strlen(a))))
			return (*envp + ft_strlen(a));
		envp++;
	}
	return ("no envp");
}
