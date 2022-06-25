/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:40:30 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:40:32 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_textures(t_win *window, char *text, t_text *t)
{
	t->img = mlx_xpm_file_to_image(window->mlx, text, &t->w, &t->h);
	if (!t->img || t->w < 1 || t->h < 1 || t->h > 256 || t->w > 256)
		exit(errors(ERR_TEXTURE));
	t->addr = (int *)mlx_get_data_addr(t->img, &t->bits_per_pixel,
			&t->line_length, &t->endian);
	if (!t->addr)
		exit(errors(ERR_MLX));
}

int		get_texture_color(t_cub *data, double wall, int i)
{
	int	color;

	if (data->pic.t == 'N')
		color = north_texture(data, wall, i);
	else if (data->pic.t == 'S')
		color = south_texture(data, wall, i);
	else if (data->pic.t == 'W')
		color = west_texture(data, wall, i);
	else
		color = east_texture(data, wall, i);
	return (color);
}

void	init_textures(t_cub *data)
{
	get_textures(&data->w, data->scene.n_texture, &data->txt_north);
	get_textures(&data->w, data->scene.w_texture, &data->txt_west);
	get_textures(&data->w, data->scene.e_texture, &data->txt_east);
	get_textures(&data->w, data->scene.s_texture, &data->txt_south);
	get_textures(&data->w, data->scene.sprite, &data->txt_sprite);
}
