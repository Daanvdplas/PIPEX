/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:16:15 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 11:20:27 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_array(char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
	return ;
}
