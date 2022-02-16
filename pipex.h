/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:17 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 14:27:03 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_fork
{
	pid_t			child;
	struct s_fork	*next;
}	t_fork;

typedef struct s_pipe
{
	int		cmd_i;
	int		cmd_lim;
	char	**envp;
	char	**path;
	char	**mycmd;
	char	**argv;
}	t_pipe;

void	pipex(t_pipe *p, int fd);

void	conv_info(t_pipe *p, char **argv);
char	**ft_split_pipex(char const *s, char c);

int		arrange_input(t_pipe *p, int input);
int		arrange_output(t_pipe *p, int output, int file2);
void	free_pipex(t_pipe *p);

void	execute_cmd(t_pipe *p);

#endif