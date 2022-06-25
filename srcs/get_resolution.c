/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:36:42 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:36:44 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	limit_res(t_cub *data, int max_x, int max_y)
{
	if (data->w.win_w > max_x)
		data->w.win_w = max_x;
	if (data->w.win_w < 320)
		data->w.win_w = 320;
	if (data->w.win_h > max_y)
		data->w.win_h = max_y;
	if (data->w.win_h < 240)
		data->w.win_h = 240;
	data->scene.end--;
}

void		get_resolution(char *s, t_cub *data)
{
	char	**res;
	int		max_x;
	int		max_y;

	if (data->w.win_h != 0 || data->w.win_w != 0)
		exit(errors(ERR_FILE));
	if (*s != ' ')
		exit(errors(ERR_SPACE));
	while (*s == ' ')
		s++;
	if (*s == '\0' || !ft_isdigit(*s))
		exit(errors(ERR_RES));
	res = ft_split(s, ' ');
	if (array_size(res) != 2)
		exit(errors(ERR_RES));
	if ((data->w.win_w = ft_atoi(res[0])) <= 0 ||
		(data->w.win_h = ft_atoi(res[1])) <= 0)
		exit(errors(ERR_RES));
	array_free(res);
	mlx_get_screen_size(data->w.mlx, &max_x, &max_y);
	limit_res(data, max_x, max_y);
}
