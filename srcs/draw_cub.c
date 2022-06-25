/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:38:18 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:38:25 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_start(t_cub *data)
{
	if (!(data->w.mlx = mlx_init()))
		exit(errors(ERR_MALLOC));
	data->w.win = mlx_new_window(data->w.mlx, data->w.win_w,
			data->w.win_h, "FDARRIN'S CUB3D");
	if (!data->w.win)
		exit(errors(ERR_MALLOC));
	data->image.img = mlx_new_image(data->w.mlx, data->w.win_w,
									data->w.win_h);
	if (!data->image.img)
		exit(errors(ERR_MALLOC));
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	if (!data->image.addr)
		exit(errors(ERR_MALLOC));
}

void	draw_screen(t_cub *data)
{
	draw_maze(data);
	draw_sprites(data);
	mlx_put_image_to_window(data->w.mlx, data->w.win, data->image.img, 0, 0);
}

void	draw_cub(t_cub *data)
{
	if (data->save == 1)
		make_screenshot(data);
	mlx_start(data);
	init_textures(data);
	draw_screen(data);
	if (mlx_hook(data->w.win, 2, 1L << 0, presskey, data) < 0)
		exit(errors(ERR_MLX));
	mlx_hook(data->w.win, 17, 1L << 17, close_win, data);
	mlx_loop(data->w.mlx);
}
