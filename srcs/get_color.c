/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:36:23 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:36:27 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	rgb_bitwise(t_cub *data, char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit(errors(ERR_COLOR));
	array_free(rgb);
	data->scene.end--;
	return (0 << 24 | r << 16 | g << 8 | b);
}

void		check_commas(char *s)
{
	int commas;

	commas = 0;
	while (*s != '\0')
	{
		if (*s == ',')
			commas++;
		s++;
	}
	if (commas != 2)
		exit(errors(ERR_COLOR));
}

void		get_color(char *s, t_cub *data)
{
	char	**rgb;
	char	el;

	el = *s++;
	if (*s != ' ')
		exit(errors(ERR_SPACE));
	while (*s == ' ')
		s++;
	if (*s == '\0')
		exit(errors(ERR_COLOR));
	check_commas(s);
	rgb = ft_split(s, ',');
	if (array_size(rgb) != 3)
		exit(errors(ERR_COLOR));
	if (el == 'F')
		data->scene.floor = rgb_bitwise(data, rgb);
	if (el == 'C')
		data->scene.ceiling = rgb_bitwise(data, rgb);
}
