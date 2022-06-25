/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:40:46 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:40:48 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int		array_free(char **array)
{
	int	i;

	i = array_size(array);
	while (i >= 0)
		free(array[i--]);
	free(array);
	return (i);
}

t_s		*ft_sp_new(double x, double y)
{
	t_s *tmp;

	if (!(tmp = (t_s *)malloc(sizeof(t_s))))
		exit(errors(ERR_MALLOC));
	tmp->sprite_x = x;
	tmp->sprite_y = y;
	tmp->dist = 0;
	tmp->angle = 0;
	tmp->collect = 1;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lst_sp(t_s **sprite, t_s *new)
{
	t_s *a;

	a = *sprite;
	if (a)
	{
		while (a->next)
			a = a->next;
		a->next = new;
	}
	else
		*sprite = new;
}

void	remove_sprite(t_cub *data, int x, int y)
{
	t_s	*t;

	t = data->sprites;
	while (t)
	{
		if (((t->sprite_x - 32) / 64 == x) && ((t->sprite_y - 32) / 64 == y))
		{
			data->scene.map[y][x] = '0';
			t->collect = 0;
			break ;
		}
		t = t->next;
	}
}
