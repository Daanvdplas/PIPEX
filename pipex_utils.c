/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:14 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 14:20:52 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipe *p)
{
	ft_free_char_array(p->path);
	ft_free_char_array(p->mycmd);
	free(p);
	return ;
}

int	arrange_output(t_pipe *p, int output, int file2)
{
	if (file2 == 1)
	{
		output = open(p->argv[p->cmd_lim + 1], \
					O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (output < 0 || output > 1024)
		{
			perror("");
			exit(errno);
		}
	}
	return (output);
}

int	arrange_input(t_pipe *p, int input)
{
	if (input == -1 && p->cmd_i == 2)
	{
		input = open(p->argv[1], O_RDONLY);
		if (input < 0 || input > 1024)
		{
			perror("");
			exit(errno);
		}
	}
	return (input);
}
