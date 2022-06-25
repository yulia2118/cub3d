/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:39:35 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:39:37 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			zero_check(int i, int j, t_cub *data)
{
	if (data->scene.map[i][j] == ' ' || data->scene.map[i][j] == '1')
		return (0);
	if (data->scene.map[i + 1][j] == ' ')
		exit(errors(ERR_MAP));
	if (data->scene.map[i][j + 1] == ' ')
		exit(errors(ERR_MAP));
	if (data->scene.map[i][j - 1] == ' ')
		exit(errors(ERR_MAP));
	if (data->scene.map[i - 1][j] == ' ')
		exit(errors(ERR_MAP));
	return (0);
}

static void	map_scale(t_win *win, t_scene *s)
{
	int map_max_side;
	int screen_max_side;

	map_max_side = s->map_x > s->map_y + 2 ? s->map_x : s->map_y + 2;
	screen_max_side = win->win_h > win->win_w ? win->win_h : win->win_w;
	win->scale = (screen_max_side / map_max_side) / 3;
}

void		get_player(int x, int y, t_cub *data)
{
	map_scale(&data->w, &data->scene);
	if (data->pl.pos == ' ')
	{
		data->pl.pos = data->scene.map[y][x];
		data->pl.pos_x = x * data->w.ppc + data->w.ppc / 2;
		data->pl.pos_y = y * data->w.ppc + data->w.ppc / 2;
	}
	else
		exit(errors(ERR_MAP));
	if (data->pl.pos == 'N')
		data->pl.angle = 3 * M_PI_2;
	else if (data->pl.pos == 'W')
		data->pl.angle = M_PI;
	else if (data->pl.pos == 'S')
		data->pl.angle = M_PI_2;
	else if (data->pl.pos == 'E')
		data->pl.angle = 0;
}

void		get_sprites(int x, int y, t_cub *data)
{
	double sprite_x;
	double sprite_y;

	sprite_x = x * 64 + 32;
	sprite_y = y * 64 + 32;
	ft_lst_sp(&data->sprites, ft_sp_new(sprite_x, sprite_y));
}

void		map_check(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->scene.map_y < 3)
		exit(errors(ERR_MAP));
	while (++i <= data->scene.map_y)
	{
		j = 0;
		while (++j < data->scene.map_x)
		{
			if (!ft_strchr(" 012NWSE", data->scene.map[i][j]))
				exit(errors(ERR_MAP));
			if (ft_strchr("NWSE", data->scene.map[i][j]))
				get_player(j, i, data);
			if (data->scene.map[i][j] == '2')
				get_sprites(j, i, data);
			zero_check(i, j, data);
		}
	}
	sprites_dist(data);
	if (data->pl.pos == ' ')
		exit(errors(ERR_MAP));
}
