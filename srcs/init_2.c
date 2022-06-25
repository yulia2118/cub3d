/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:37:32 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:37:34 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	img_init(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.bits_per_pixel = 0;
	img.line_length = 0;
	img.endian = 0;
	return (img);
}

t_text	text_init(void)
{
	t_text	text;

	text.w = 0;
	text.h = 0;
	text.img = NULL;
	text.addr = 0;
	text.bits_per_pixel = 0;
	text.line_length = 0;
	text.endian = 0;
	return (text);
}

t_pic	pic_init(void)
{
	t_pic	pic;

	pic.ray_len = 0.0000;
	pic.ax = 0;
	pic.ay = 0;
	pic.ax_y = 0;
	pic.ay_y = 0;
	pic.t = 't';
	pic.t_y = 't';
	pic.expose_map = -1;
	return (pic);
}
