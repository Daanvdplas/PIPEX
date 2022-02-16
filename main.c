/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:10 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 14:26:49 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	p;
	int		fd;

	if (argc < 4)
		return (0);
	fd = -1;
	p.argv = argv;
	p.cmd_i = 2;
	p.cmd_lim = argc - 2;
	p.envp = envp;
	pipex(&p, fd);
	return (0);
}
