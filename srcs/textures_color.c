/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:40:15 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:40:17 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		south_texture(t_cub *data, double wall, int i)
{
	int		column;
	double	scale;
	int		*dst;

	scale = wall / data->txt_south.h;
	i = (int)(i / scale);
	column = 63 - (int)(data->pic.ax) % (int)data->w.ppc;
	dst = (int *)(data->txt_south.addr + (i * data->txt_south.w + column));
	return (*dst);
}

int		north_texture(t_cub *data, double wall, int i)
{
	int		column;
	double	scale;
	int		*dst;

	scale = wall / data->txt_north.h;
	i = (int)(i / scale);
	column = (int)data->pic.ax % (int)data->w.ppc;
	dst = (int *)(data->txt_north.addr + (i * data->txt_north.w + column));
	return (*dst);
}

int		west_texture(t_cub *data, double wall, int i)
{
	int		column;
	double	scale;
	int		*dst;

	scale = wall / data->txt_west.h;
	i = (int)(i / scale);
	column = 63 - (int)data->pic.ay % (int)data->w.ppc;
	dst = (int *)(data->txt_west.addr + (i * data->txt_west.w + column));
	return (*dst);
}

int		east_texture(t_cub *data, double wall, int i)
{
	int		column;
	double	scale;
	int		*dst;

	scale = wall / data->txt_east.h;
	i = (int)(i / scale);
	column = (int)data->pic.ay % (int)data->w.ppc;
	dst = (int *)(data->txt_east.addr + (i * data->txt_east.w + column));
	return (*dst);
}

int		sprite_texture(t_cub *data, double sprite, double x, double y)
{
	double	scale;
	int		*dst;

	scale = sprite / data->txt_sprite.h;
	x = (int)(x / scale);
	y = (int)(y / scale);
	dst = (int *)(data->txt_sprite.addr + (int)(y * data->txt_sprite.w + x));
	return (*dst);
}
