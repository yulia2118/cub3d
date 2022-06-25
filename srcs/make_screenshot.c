/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:40:00 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:40:02 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	write_bmp(t_cub *data, char *bmp)
{
	unsigned int	size;
	int				fd;

	ft_memcpy(bmp, "BM", 2);
	size = sizeof(int) * data->w.win_w * data->w.win_h + 54;
	ft_memcpy(bmp + 2, &size, 4);
	size = 54;
	ft_memcpy(bmp + 10, &size, 4);
	size = 40;
	ft_memcpy(bmp + 14, &size, 4);
	ft_memcpy(bmp + 18, &data->w.win_w, 4);
	*(unsigned int*)(bmp + 22) = -data->w.win_h;
	size = 1;
	ft_memcpy(bmp + 26, &size, 2);
	ft_memcpy(bmp + 28, &data->image.bits_per_pixel, 2);
	size = sizeof(int) * data->w.win_w * data->w.win_h;
	ft_memcpy(bmp + 34, &size, 4);
	ft_memcpy(bmp + 54, data->image.addr,
			sizeof(int) * (data->w.win_h * data->w.win_w));
	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	write(fd, bmp,
			sizeof(int) * (data->w.win_w * data->w.win_h) + 54);
	close(fd);
}

static void	render_first_image(t_cub *data, char **bmp)
{
	int				x;
	int				y;
	unsigned int	size;

	x = data->w.win_w;
	y = data->w.win_h;
	while (data->w.win_h % 64 != 0 && data->w.win_h >= 0)
		data->w.win_h--;
	while (data->w.win_w % 64 != 0 && data->w.win_w >= 0)
		data->w.win_w--;
	mlx_start(data);
	init_textures(data);
	draw_screen(data);
	size = data->w.win_w * data->w.win_h;
	*bmp = (char *)ft_calloc(1, sizeof(int) * size + 54);
	write_bmp(data, *bmp);
	data->w.win_w = x;
	data->w.win_h = y;
}

void		make_screenshot(t_cub *data)
{
	char	*bmp;

	render_first_image(data, &bmp);
	free(bmp);
	exit(0);
}
