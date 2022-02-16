/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:14 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 14:18:47 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**create_path(char *str)
{
	char	**arr;
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = ft_substr(str, 5, len - 5);
	ft_check_malloc(new_str);
	arr = ft_split(new_str, ':');
	free(new_str);
	ft_check_malloc(*(arr));
	i = 0;
	while (arr[i])
	{
		new_str = ft_strjoin(arr[i], "/");
		free(arr[i]);
		arr[i] = new_str;
		ft_check_malloc(arr[i]);
		i++;
	}
	return (arr);
}

static void	make_path(t_pipe *p)
{
	int	i;

	i = 0;
	while ((p->envp)[i])
	{
		if (ft_strnstr((p->envp)[i], "PATH=", 5))
			break ;
		i++;
	}
	p->path = create_path((p->envp)[i]);
	ft_check_malloc(*(p->path));
	return ;
}

void	conv_info(t_pipe *p, char **argv)
{	
	if (p->cmd_i == 2)
		make_path(p);
	p->mycmd = ft_split_pipex(argv[p->cmd_i], ' ');
	ft_check_malloc(*(p->mycmd));
	return ;
}
