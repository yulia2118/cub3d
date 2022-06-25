/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:39:23 by fdarrin           #+#    #+#             */
/*   Updated: 2020/10/19 21:39:25 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*map_add(char *content, int c)
{
	char	*t;
	int		i;

	t = content;
	if (!(content = (char *)ft_calloc(1, sizeof(char) * (c + 1))))
		exit(errors(ERR_MALLOC));
	i = -1;
	while (t[++i] != '\0')
		content[i] = t[i];
	c -= ft_strlen(t);
	while (c-- > 0)
		content[i++] = ' ';
	free(t);
	return (content);
}

void		map_fill(t_list **map, size_t len)
{
	t_list *tmp;

	tmp = *map;
	while (tmp)
	{
		if (ft_strlen(tmp->content) < len)
			tmp->content = map_add(tmp->content, len);
		tmp = tmp->next;
	}
}

static char	*add_spaces(char *line)
{
	char	*right;
	char	*left;

	left = ft_strjoin(" ", line);
	right = ft_strjoin(left, " ");
	if (!right || !left)
		exit(errors(ERR_MALLOC));
	free(line);
	free(left);
	return (right);
}

void		get_list(int fd, t_list **l_map, t_cub *data)
{
	int		bwr;
	char	*line;
	int		end_map;

	end_map = 0;
	while ((bwr = get_next_line(fd, &line, 1)) >= 0)
	{
		if (*line == '\0')
			end_map = 1;
		if (*line != '\0' && end_map == 1)
			exit(errors(ERR_MAP));
		line = add_spaces(line);
		ft_lstadd_back(l_map, ft_lstnew(line));
		if (!l_map)
			exit(errors(ERR_MALLOC));
		if (data->scene.map_x < (int)ft_strlen(line))
			data->scene.map_x = (int)ft_strlen(line);
		data->scene.map_y++;
		if (bwr == 0)
			break ;
	}
}

void		get_map(int fd, t_cub *data)
{
	t_list	*l_map;
	char	*line;

	l_map = NULL;
	while (get_next_line(fd, &line, 1) > 0)
	{
		if (*line != '\0')
		{
			line = add_spaces(line);
			ft_lstadd_back(&l_map, ft_lstnew(line));
			if (!l_map)
				exit(errors(ERR_MALLOC));
			if (data->scene.map_x < (int)ft_strlen(line))
				data->scene.map_x = (int)ft_strlen(line);
			data->scene.map_y++;
			break ;
		}
		free(line);
	}
	get_list(fd, &l_map, data);
	map_fill(&l_map, data->scene.map_x);
	data->scene.map = map_make(&l_map, data->scene.map_x);
}
