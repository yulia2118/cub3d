/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:39:23 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:39:25 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*add_empty(int len)
{
	char	*empty;
	int		i;

	i = 0;
	if (!(empty = (char *)malloc(sizeof(char) * (len + 1))))
		exit(errors(ERR_MALLOC));
	while (i < len)
		empty[i++] = ' ';
	empty[i] = '\0';
	return (empty);
}

char	**map_make(t_list **map, int len)
{
	int		i;
	int		j;
	t_list	*t;
	char	**map_array;

	t = *map;
	i = ft_lstsize(t);
	j = 1;
	if (!(map_array = (char **)ft_calloc(i + 3, sizeof(char *))))
		exit(errors(ERR_MALLOC));
	*map_array = add_empty(len);
	while (t)
	{
		map_array[j] = t->content;
		t = t->next;
		j++;
	}
	map_array[j] = add_empty(len);
	ft_lstclean(map);
	return (map_array);
}
