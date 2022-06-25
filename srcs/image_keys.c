/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:38:05 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:38:06 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_sliding(t_cub *d, double x, double y)
{
	if (ft_strchr("1 ", d->scene.map[(int)(d->pl.pos_y / 64)][(int)(x / 64)]))
		x = d->pl.pos_x;
	if (ft_strchr("1 ", d->scene.map[(int)(y / 64)][(int)(d->pl.pos_x / 64)]))
		y = d->pl.pos_y;
	if (ft_strchr("1 ", d->scene.map[(int)(y / 64)][(int)(x / 64)]))
	{
		x = d->pl.pos_x;
		y = d->pl.pos_y;
	}
	if (d->scene.map[(int)(y / 64)][(int)(x / 64)] == '2')
		remove_sprite(d, (int)(x / 64), (int)(y / 64));
	d->pl.pos_x = x;
	d->pl.pos_y = y;
}

void	wasd(t_cub *d, int key)
{
	double angle;
	double x;
	double y;

	if (key == DOWN)
		angle = d->pl.angle - M_PI;
	else if (key == LEFT)
		angle = d->pl.angle - M_PI_2;
	else if (key == RIGHT)
		angle = d->pl.angle + M_PI_2;
	else
		angle = d->pl.angle;
	x = d->pl.pos_x + SPEED * cos(angle);
	y = d->pl.pos_y + SPEED * sin(angle);
	wall_sliding(d, x, y);
}

void	turns(t_player *p, int keycode)
{
	p->angle = (keycode == TURN_R) ? (p->angle + 0.1) : (p->angle - 0.1);
	p->angle = p->angle < 0 ? p->angle + 2 * M_PI : p->angle;
	p->angle = p->angle > 2 * M_PI ? p->angle - 2 * M_PI : p->angle;
}

int		presskey(int keycode, t_cub *data)
{
	mlx_destroy_image(data->w.mlx, data->image.img);
	if (keycode == ESC)
		exit(0);
	data->image.img = mlx_new_image(data->w.mlx,
									data->w.win_w, data->w.win_h);
	if (!data->image.img)
		exit(errors(ERR_MLX));
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length, &data->image.endian);
	if (!data->image.addr)
		exit(errors(ERR_MLX));
	if (keycode == DOWN || keycode == UP || keycode == RIGHT || keycode == LEFT)
		wasd(data, keycode);
	if (keycode == TURN_L || keycode == TURN_R)
		turns(&data->pl, keycode);
	draw_screen(data);
	return (0);
}

int		close_win(t_cub *data)
{
	mlx_destroy_window(data->w.mlx, data->w.win);
	exit(0);
}
