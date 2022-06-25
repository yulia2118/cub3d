/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:39:48 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:39:50 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	x_ray_off(t_cub *d, double angle)
{
	if (angle > 0 && angle < M_PI)
	{
		d->r_x.ay = (int)(d->pl.pos_y / d->w.ppc) *
					d->w.ppc + d->w.ppc;
		d->r_x.dy = d->w.ppc;
	}
	else if (angle > M_PI && angle < 2 * M_PI)
	{
		d->r_x.ay = (int)(d->pl.pos_y / d->w.ppc) *
					d->w.ppc - 0.0000000001;
		d->r_x.dy = (-1) * d->w.ppc;
	}
	else
		return (-1);
	if (angle == M_PI_2 || angle == 3 * M_PI_2)
	{
		d->r_x.ax = d->pl.pos_x;
		d->r_x.dx = 0;
	}
	else
	{
		d->r_x.dx = (d->r_x.dy / tan(angle));
		d->r_x.ax = (d->pl.pos_x - (d->pl.pos_y - d->r_x.ay) / tan(angle));
	}
	return (0);
}

double	intersect_x(t_cub *data, double angle)
{
	double ray;
	double x;
	double y;

	if ((x_ray_off(data, angle) == -1))
		return (INFINITY);
	y = data->r_x.ay / data->w.ppc;
	x = data->r_x.ax / data->w.ppc;
	while (x > 0 && y > 0 && x < data->scene.map_x && y < data->scene.map_y &&
		data->scene.map[(int)y][(int)x] != '1' &&
		data->scene.map[(int)y][(int)x] != ' ')
	{
		data->r_x.ax += data->r_x.dx;
		data->r_x.ay += data->r_x.dy;
		x = data->r_x.ax / data->w.ppc;
		y = data->r_x.ay / data->w.ppc;
	}
	ray = sqrt(pow(data->pl.pos_x - data->r_x.ax, 2) +
			pow(data->pl.pos_y - data->r_x.ay, 2));
	data->pic.ax = data->r_x.ax;
	data->pic.ay = data->r_x.ay;
	data->pic.t = data->r_x.dy < 0 ? 'N' : 'S';
	return (fabs(ray));
}

double	y_ray_off(t_cub *d, double angle)
{
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
	{
		d->r_y.ax = (int)(d->pl.pos_x / d->w.ppc) *
					d->w.ppc - 0.0000000001;
		d->r_y.dx = (-1) * d->w.ppc;
	}
	else if (angle == M_PI_2 || angle == 3 * M_PI_2)
		return (-1);
	else
	{
		d->r_y.ax = (int)(d->pl.pos_x / d->w.ppc) *
					d->w.ppc + d->w.ppc;
		d->r_y.dx = d->w.ppc;
	}
	if (angle == 0 || angle == M_PI)
	{
		d->r_y.ay = d->pl.pos_y;
		d->r_y.dy = 0;
	}
	else
	{
		d->r_y.dy = (d->r_y.dx * tan(angle));
		d->r_y.ay = (d->pl.pos_y - (d->pl.pos_x - d->r_y.ax) * tan(angle));
	}
	return (0);
}

double	intersect_y(t_cub *data, double angle)
{
	double ray;
	double x;
	double y;

	if ((y_ray_off(data, angle) == -1))
		return (INFINITY);
	x = data->r_y.ax / data->w.ppc;
	y = data->r_y.ay / data->w.ppc;
	while (x > 0 && y > 0 && x < data->scene.map_x && y < data->scene.map_y &&
		data->scene.map[(int)y][(int)x] != '1' &&
		data->scene.map[(int)y][(int)x] != ' ')
	{
		data->r_y.ax += data->r_y.dx;
		data->r_y.ay += data->r_y.dy;
		x = data->r_y.ax / data->w.ppc;
		y = data->r_y.ay / data->w.ppc;
	}
	ray = sqrt(pow(data->pl.pos_x - data->r_y.ax, 2) +
			pow(data->pl.pos_y - data->r_y.ay, 2));
	data->pic.ax_y = data->r_y.ax;
	data->pic.ay_y = data->r_y.ay;
	data->pic.t_y = data->r_y.dx < 0 ? 'W' : 'E';
	return (fabs(ray));
}

void	raycasting(t_cub *data, double ray_angle)
{
	double inter_x;
	double inter_y;

	inter_x = intersect_x(data, ray_angle);
	inter_y = intersect_y(data, ray_angle);
	data->pic.ray_len = (inter_x < inter_y) ? inter_x : inter_y;
	if (inter_x > inter_y)
	{
		data->pic.ax = data->pic.ax_y;
		data->pic.ay = data->pic.ay_y;
		data->pic.t = data->pic.t_y;
	}
}
