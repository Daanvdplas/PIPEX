/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:14 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 11:45:43 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_handling(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
		exit(2);
	}
	else
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

static void	execute_with_path(t_pipe *p)
{
	char	*str;

	str = p->mycmd[0];
	if (execve(str, p->mycmd, p->envp) == 1)
	{
		perror("");
		exit(errno);
	}
	return ;
}

void	execute_cmd(t_pipe *p)
{
	int		i;
	char	*str;

	if (access(p->mycmd[0], F_OK && X_OK) == 0)
		execute_with_path(p);
	i = 0;
	while ((p->path)[i])
	{
		str = ft_strjoin((p->path)[i], (p->mycmd)[0]);
		ft_check_malloc(str);
		if (access(str, F_OK && X_OK) == 0)
		{
			if (execve(str, p->mycmd, p->envp) == -1)
			{
				perror("");
				exit(errno);
			}
		}
		free(str);
		i++;
	}
	error_handling(p->mycmd[0]);
}
