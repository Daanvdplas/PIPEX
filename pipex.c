/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:14 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 14:22:02 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	waitpid_forks(t_fork *forks)
{
	int		status;
	t_fork	*tmp;

	while (forks->next)
	{
		waitpid(forks->child, &status, 0);
		tmp = forks;
		forks = forks->next;
		free(tmp);
	}
	waitpid(forks->child, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return ;
}

static void	for_child(t_pipe *p, int *end, int fd, int file2)
{
	int	input;
	int	output;

	close(end[0]);
	input = arrange_input(p, fd);
	if (dup2(input, STDIN_FILENO) < 0)
	{
		perror("");
		close(input);
	}
	output = arrange_output(p, end[1], file2);
	if (dup2(output, STDOUT_FILENO) < 0)
	{
		perror("");
		close(output);
	}
	execute_cmd(p);
	return ;
}

static int	handle_fork(t_pipe *p, t_fork *a_fork, int fd)
{
	int	file2;
	int	end[2];

	if (p->cmd_i == p->cmd_lim)
		file2 = 1;
	else
		file2 = 0;
	if (pipe(end) == -1)
	{
		perror("");
		exit(errno);
	}
	a_fork->child = fork();
	if (a_fork->child < 0)
	{
		perror("");
		exit(errno);
	}
	else if (a_fork->child == 0)
		for_child(p, end, fd, file2);
	else if (a_fork->child > 0)
		close(end[1]);
	return (end[0]);
}

static t_fork	*new_fork(t_fork *a_fork)
{
	t_fork	*new_fork;

	new_fork = (t_fork *)malloc(sizeof(t_fork));
	ft_check_malloc(new_fork);
	new_fork->next = NULL;
	if (!a_fork)
		a_fork = new_fork;
	else
	{
		a_fork->next = new_fork;
		a_fork = a_fork->next;
	}
	return (a_fork);
}

void	pipex(t_pipe *p, int fd)
{
	bool	first;
	t_fork	*head_forks;
	t_fork	*a_fork;

	a_fork = NULL;
	first = true;
	while (p->cmd_i <= p->cmd_lim)
	{
		a_fork = new_fork(a_fork);
		if (first)
		{
			head_forks = a_fork;
			first = false;
		}
		conv_info(p, p->argv);
		fd = handle_fork(p, a_fork, fd);
		ft_free_char_array(p->mycmd);
		(p->cmd_i)++;
	}
	waitpid_forks(head_forks);
	free_pipex(p);
	close(fd);
}
