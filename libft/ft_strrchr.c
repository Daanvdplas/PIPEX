/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:55:14 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:25 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			while (i > 0)
			{
				s++;
				i--;
			}
			return ((char *)s);
		}
		i--;
	}
	while (*s)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
