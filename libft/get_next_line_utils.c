/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:25:38 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/22 21:51:32 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_next_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

size_t	line_len(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

size_t	buffsize(char *buff)
{
	size_t i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i] != '\0')
		i++;
	return (i);
}
