/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:37:18 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:37:20 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_win		window_init(void)
{
	t_win	window;

	window.mlx = NULL;
	window.win = NULL;
	window.x = 0.0;
	window.y = 0.0;
	window.win_h = 0;
	window.win_w = 0;
	window.scale = 0;
	window.ppc = 64;
	return (window);
}

t_player	player_init(void)
{
	t_player	player;

	player.pos = ' ';
	player.angle = 0.0;
	player.fov = M_PI / 3;
	player.pos_x = 0;
	player.pos_y = 0;
	player.viewport = 0;
	return (player);
}

t_scene		scene_init(void)
{
	t_scene	scene;

	scene.n_texture = NULL;
	scene.s_texture = NULL;
	scene.w_texture = NULL;
	scene.e_texture = NULL;
	scene.sprite = NULL;
	scene.floor = -1;
	scene.ceiling = -1;
	scene.end = 8;
	scene.map = NULL;
	scene.map_x = 0;
	scene.map_y = 0;
	return (scene);
}

void		init_cub(t_cub *data)
{
	data->left_sprites = 0;
	data->scene = scene_init();
	data->pl = player_init();
	data->w = window_init();
	data->image = img_init();
	data->txt_north = text_init();
	data->txt_west = text_init();
	data->txt_south = text_init();
	data->txt_east = text_init();
	data->txt_sprite = text_init();
	data->pic = pic_init();
	data->sprites = NULL;
}
