/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:37:49 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:37:51 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
	char *dst;

	dst = data->image.addr + (y * data->image.line_length +
			x * (data->image.bits_per_pixel / 8));
	*(unsigned int *)dst = (color);
}

void	put_colors(t_cub *data, double wall, double actual_wall, int x)
{
	int start_y;
	int i;
	int ceiling;
	int color;

	start_y = 0;
	i = (int)(actual_wall - wall) / 2;
	ceiling = (data->w.win_h - (int)wall) / 2;
	while (start_y < ceiling)
		my_mlx_pixel_put(data, x, start_y++, data->scene.ceiling);
	while (start_y < (ceiling + (int)wall))
	{
		color = get_texture_color(data, actual_wall, i);
		my_mlx_pixel_put(data, x, start_y++, color);
		i++;
	}
	while (start_y < data->w.win_h)
		my_mlx_pixel_put(data, x, start_y++, data->scene.floor);
}

void	line_draw(t_cub *d, double angle, int x)
{
	double	wall_h;
	double	wall;
	double	actual_wall;

	wall_h = d->w.ppc / 5;
	d->pl.viewport = (d->w.win_w / 2) / (tan(d->pl.fov / 2));
	wall = (d->pl.viewport / (d->pic.ray_len *
			cos(angle - d->pl.angle) * wall_h)) * d->w.win_h;
	actual_wall = wall;
	if (wall > d->w.win_h)
		wall = d->w.win_h;
	put_colors(d, wall, actual_wall, x);
}

void	draw_maze(t_cub *d)
{
	double	ray_angle;
	int		i;

	if (!(d->pic.arr = (double *)malloc(sizeof(double) * d->w.win_w)))
		exit(errors(ERR_MALLOC));
	ray_angle = d->pl.angle - d->pl.fov / 2;
	i = 0;
	while (i < d->w.win_w)
	{
		if (ray_angle > 2 * M_PI)
			ray_angle -= 2 * M_PI;
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
		raycasting(d, ray_angle);
		d->pic.arr[i] = d->pic.ray_len;
		line_draw(d, ray_angle, i);
		ray_angle += d->pl.fov / d->w.win_w;
		i++;
	}
}
