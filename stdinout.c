/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:25:14 by sryou             #+#    #+#             */
/*   Updated: 2022/09/26 18:52:36 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    stdin_manage(int fd_stdin, t_list *list_stdin)
{
    char    *buf;

    while (list_stdin)
    {
        while (1)
        {
            buf = get_next_line(*(int *)(list_stdin->content));
            if (buf == 0)
                break ;
            ft_putstr_fd(buf, fd_stdin);
            free(buf);
        }
        list_stdin = list_stdin->next;
    }
    close(fd_stdin);
}

void    stdout_manage(int fd_stdout, t_list *list_stdout)
{
    char    *buf;
    t_list  *list_temp;

    while (1)
    {
        buf = get_next_line(fd_stdout);
        if (buf == 0)
            break ;
        list_temp = list_stdout;
        while (list_temp)
        {
            ft_putstr_fd(buf, *(int *)(list_stdout->content));
            list_temp = list_temp->next;
        }
        free(buf);
    }
    while (list_stdout)
    {
        close(*(int *)(list_stdout->content));
        list_stdout = list_stdout->next;
    }
}
