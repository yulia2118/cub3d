/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:43:37 by fdarrin           #+#    #+#             */
/*   Updated: 2020/09/12 21:43:41 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include "math.h"
# include "../libft/libft.h"
# include "fcntl.h"
# include "unistd.h"
# include "string.h"
# define SPEED 10
# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define TURN_L 123
# define TURN_R 124

typedef struct	s_player
{
	char		pos;
	double		angle;
	double		fov;
	double		pos_x;
	double		pos_y;
	double		viewport;
}				t_player;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_scene
{
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	char		*sprite;
	int			floor;
	int			ceiling;
	int			end;
	char		**map;
	int			map_x;
	int			map_y;
}				t_scene;

typedef struct	s_win {
	void		*mlx;
	void		*win;
	double		x;
	double		y;
	int			win_h;
	int			win_w;
	double		ppc;
	int			scale;
}				t_win;

typedef struct	s_pic
{
	double		ray_len;
	double		ax;
	double		ay;
	double		ax_y;
	double		ay_y;
	char		t;
	char		t_y;
	double		*arr;
	int			expose_map;
}				t_pic;

typedef struct	s_text
{
	int			w;
	int			h;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_text;

typedef struct	s_ray
{
	double		dx;
	double		dy;
	double		ax;
	double		ay;
	double		x;
	double		y;
}				t_ray;

typedef struct	s_s
{
	double		sprite_x;
	double		sprite_y;
	double		dist;
	double		angle;
	int			collect;
	struct s_s	*next;
}				t_s;

typedef struct	s_cub
{
	int			save;
	int			left_sprites;
	t_scene		scene;
	t_player	pl;
	t_win		w;
	t_img		image;
	t_pic		pic;
	t_text		txt_north;
	t_text		txt_west;
	t_text		txt_south;
	t_text		txt_east;
	t_text		txt_sprite;
	t_s			*sprites;
	t_ray		r_x;
	t_ray		r_y;
}				t_cub;

enum			e_errors
{
	ERR_TEXTURE,
	ERR_MAP,
	ERR_MLX,
	ERR_RES,
	ERR_FILE,
	ERR_SPACE,
	ERR_COLOR,
	ERR_MALLOC,
	ERR_ARGS,
	ERR_PARAM,
	ERR_FD
};

void			init_cub(t_cub	*data);
t_scene			scene_init(void);
t_player		player_init(void);
t_win			window_init(void);
t_text			text_init(void);
t_img			img_init(void);
t_pic			pic_init(void);
void			get_resolution(char *s, t_cub *data);
void			get_color(char *s, t_cub *data);
void			get_texture_path(char *s, t_cub *data);
void			get_map(int fd, t_cub *data);
char			**map_make(t_list **map, int len);
void			map_check(t_cub *data);
void			sprites_dist(t_cub *data);
void			draw_cub(t_cub *data);
void			make_screenshot(t_cub *data);
void			init_textures(t_cub *data);
void			draw_maze(t_cub *d);
void			draw_sprites(t_cub *data);
void			raycasting(t_cub *data, double ray_angle);
int				get_texture_color(t_cub *data, double wall, int i);
int				north_texture(t_cub *data, double wall, int i);
int				south_texture(t_cub *data, double wall, int i);
int				west_texture(t_cub *data, double wall, int i);
int				east_texture(t_cub *data, double wall, int i);
int				sprite_texture(t_cub *data, double sprite, double x, double y);
void			my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void			ft_lst_sp(t_s **sprite, t_s *new);
t_s				*ft_sp_new(double x, double y);
int				array_size(char **array);
int				array_free(char **array);
void			draw_screen(t_cub *data);
void			mlx_start(t_cub *data);
int				presskey(int keycode, t_cub *data);
int				close_win(t_cub *data);
void			remove_sprite(t_cub *data, int x, int y);
int				errors(int code);

#endif
