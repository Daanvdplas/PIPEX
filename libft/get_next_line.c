/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:14 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:48 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*letsgo(char *line, int fd, char *buffer)
{
	int			size_line;
	int			buffer_size;

	size_line = 0;
	buffer_size = check_buffer(buffer);
	size_line += buffer_size;
	line = add_buffer(line, buffer, buffer_size, size_line);
	if (!check_line(line))
		return (line);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		buffer_size = check_buffer(buffer);
		size_line += buffer_size;
		line = add_buffer(line, buffer, buffer_size, size_line);
		if (!check_line(line))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > 1024 || read(fd, buffer, 0) == -1)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	ft_check_malloc(line);
	line[0] = '\0';
	line = letsgo(line, fd, buffer);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
