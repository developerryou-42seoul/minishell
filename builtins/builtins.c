# include "minishell.h"

int    builtin_echo(t_block *block)
{
    (void)block;
    return (0);
}
int    builtin_cd(t_block *block)
{
    (void)block;
    return (0);
}
int    builtin_pwd(t_block *block)
{
    (void)block;
    return (0);
}
int    builtin_unset(t_block *block)
{
    (void)block;
    return (0);
}
int    builtin_env(t_block *block)
{
    (void)block;
    return (0);
}
int    builtin_exit(t_block *block)
{
    (void)block;
    return (0);
}

int	check_builtins(t_block *block)
{
    char    *exec;

    exec = block->argv->content;
    if (ft_strlen(exec) == ft_strlen("echo") && ft_strncmp(exec, "echo", ft_strlen("echo")) == 0)
        return (1);
    else if (ft_strlen(exec) == ft_strlen("cd") && ft_strncmp(exec, "cd", ft_strlen("cd")) == 0)
        return (1);
    else if (ft_strlen(exec) == ft_strlen("pwd") && ft_strncmp(exec, "pwd", ft_strlen("pwd")) == 0)
        return (1);
    else if (ft_strlen(exec) == ft_strlen("export") && ft_strncmp(exec, "export", ft_strlen("export")) == 0)
        return (1);
    else if (ft_strlen(exec) == ft_strlen("unset") && ft_strncmp(exec, "unset", ft_strlen("unset")) == 0)
        return (1);
    else if (ft_strlen(exec) == ft_strlen("env") && ft_strncmp(exec, "env", ft_strlen("env")) == 0)
        return (1);
    else if (ft_strlen(exec) == ft_strlen("exit") && ft_strncmp(exec, "exit", ft_strlen("exit")) == 0)
        return (1);
    else
        return (0);
}
int	manage_builtins(t_block *block)
{
    char    *exec;

    exec = block->argv->content;
    if (ft_strlen(exec) == ft_strlen("echo") && ft_strncmp(exec, "echo", ft_strlen("echo")) == 0)
        return builtin_echo(block);
    else if (ft_strlen(exec) == ft_strlen("cd") && ft_strncmp(exec, "cd", ft_strlen("cd")) == 0)
        return builtin_cd(block);
    else if (ft_strlen(exec) == ft_strlen("pwd") && ft_strncmp(exec, "pwd", ft_strlen("pwd")) == 0)
        return builtin_pwd(block);
    else if (ft_strlen(exec) == ft_strlen("export") && ft_strncmp(exec, "export", ft_strlen("export")) == 0)
        return builtin_export(block);
    else if (ft_strlen(exec) == ft_strlen("unset") && ft_strncmp(exec, "unset", ft_strlen("unset")) == 0)
        return builtin_unset(block);
    else if (ft_strlen(exec) == ft_strlen("env") && ft_strncmp(exec, "env", ft_strlen("env")) == 0)
        return builtin_env(block);
    else if (ft_strlen(exec) == ft_strlen("exit") && ft_strncmp(exec, "exit", ft_strlen("exit")) == 0)
        return builtin_exit(block);
    else
        return (255);
}
