/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:17:41 by junekim           #+#    #+#             */
/*   Updated: 2022/09/29 18:23:16 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <stdlib.h>
# include <termcap.h>
# include <sys/termios.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	int		past_return;
	char	**envp;
}	t_data;

int	cd(char **argv, t_data *t_envp)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	if (len != 2)
		exit(1);
	
}
