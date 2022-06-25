/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:44:46 by fdarrin           #+#    #+#             */
/*   Updated: 2020/09/12 21:44:51 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		errors(int code)
{
	if (code == ERR_MALLOC)
		ft_putstr_fd("Error\nMalloc failed\n", 1);
	else if (code == ERR_ARGS)
		ft_putstr_fd("Error\nWrong number of arguments\n", 1);
	else if (code == ERR_PARAM)
		ft_putstr_fd("Error\nInvalid parameters\n", 1);
	else if (code == ERR_FD)
		ft_putstr_fd("Error\nBad file descriptor\n", 1);
	else if (code == ERR_TEXTURE)
		ft_putstr_fd("Error\nBad texture\n", 1);
	else if (code == ERR_MAP)
		ft_putstr_fd("Error\nBad map format\n", 1);
	else if (code == ERR_MLX)
		ft_putstr_fd("Error\nMLX failed\n", 1);
	else if (code == ERR_RES)
		ft_putstr_fd("Error\nBad resolution data\n", 1);
	else if (code == ERR_FILE)
		ft_putstr_fd("Error\nBad map file\n", 1);
	else if (code == ERR_SPACE)
		ft_putstr_fd("Error\nNo space after identifier\n", 1);
	else if (code == ERR_COLOR)
		ft_putstr_fd("Error\nBad color format\n", 1);
	return (0);
}

void	read_file(int fd, t_cub *data)
{
	char	*line;
	int		code;

	while (data->scene.end > 0)
	{
		code = get_next_line(fd, &line, 0);
		if (code == -1)
			exit(errors(ERR_MALLOC));
		if (code == 0)
			exit(errors(ERR_FILE));
		if (*line != '\0')
		{
			while (*line == ' ')
				line++;
			if (*line == '\0')
				exit(errors(ERR_FILE));
			if (*line == 'R')
				get_resolution(line + 1, data);
			else if (*line == 'F' || *line == 'C')
				get_color(line, data);
			else
				get_texture_path(line, data);
		}
		free(line);
	}
}

void	check_map_file(char *s)
{
	if (!s || ft_strlen(s) < 5)
		exit(errors(ERR_PARAM));
	s += ft_strlen(s) - 4;
	if (ft_strncmp(s, ".cub", 4))
		exit(errors(ERR_PARAM));
}

int		main(int argc, char **argv)
{
	int		fd;
	t_cub	data;

	if (argc < 2 || argc > 3)
		exit(errors(ERR_ARGS));
	check_map_file(argv[1]);
	if (argv[2])
	{
		if (ft_strlen(argv[2]) != 6)
			exit(errors(ERR_PARAM));
		if (ft_strncmp(argv[2], "--save", 6))
			exit(errors(ERR_PARAM));
		data.save = 1;
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit(errors(ERR_FD));
	init_cub(&data);
	read_file(fd, &data);
	get_map(fd, &data);
	map_check(&data);
	close(fd);
	draw_cub(&data);
	return (0);
}
