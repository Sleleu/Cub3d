/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:50:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/15 18:00:57 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include "struct.h"
# include "../libft/libft.h"

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define SPACE			32

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_L			65361
# define KEY_R			65363

enum	e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/* ********************************************************** */
/*                           MAIN                             */
/* ********************************************************** */

/* MAIN */

void	bzero_struct(t_map *map);
int		ft_test_file(char *argv);

/* FREE_FUNCTIONS */

void	destroy_image(t_map *map);
void	free_rgb_texture(t_map *map);
void	free_double_array(char **str);
int		close_game(t_map *map);

/* ********************************************************** */
/*                           PARSING                          */
/* ********************************************************** */

/* PARSE */

void	parse_error(t_map *map, char *message);
void	ft_read_map(int fd, t_map *map);
int		ft_parse_map(t_map *map, int fd);

/* UTILS */

int		is_valid_char(char c, char *valid_char);
int		ft_strlen_cub3d(char *str);
char	*ft_resize_line(char *str, int size);
char	*ft_strjoin_cub3d(char *s1, char *s2);

/* WALL_ERROR */

int		check_column(char **column, int y, int x, int size_y);
int		vertical_check(t_map *map, int y, int x);
int		check_line(t_map *map, char *line, int x);
int		horizontal_check(t_map *map, int y, int x);
int		ft_wall_error(t_map *map);

/* MAP_STAT */

void	assign_player_pos(t_map *map, char direction, int i, int j);
void	set_size_data(t_map *map, char **array, int i, int j);
int		get_map_stat(t_map *map, char *line);

/* PARSE_RGB_TEXTURE */

void	get_texture_path(t_map *map, char **path, char **split_line);
int		parse_rgb_line(char *line);
int		check_rgb(int *rgb, char *line);
void	get_rgb(t_map *map, int *rgb, char **split_line);

/* ********************************************************** */
/*                           GAME                             */
/* ********************************************************** */

/* KEY_EVENTS */

int		key_hook(int keycode, t_map *map);
int		mouse_rotate_hook(int x, int y, t_map *map);
int		mouse_hook(int keycode, int x, int y, t_map *map);

/* INIT_GAME */

void	game_error(t_map *map, char *message);
void	ft_init_game_stat(t_map *map);
void	ft_init_img(t_map *map);
int		ft_init_game(t_map *map);

/* MOVES */

void	move(t_map *map, double next_x, double next_y, char sign);
void	rotate(t_map *map, double rot_spd);
void	rotate_east_west(t_map *map, double rot_spd);

/* ********************************************************** */
/*                           RAYCASTING                       */
/* ********************************************************** */

/* RAYCASTING */

void	get_delta_dist(t_map *map);
void	get_step(t_map *map);
void	digital_differential_analyser(t_map *map);
void	init_raycasting(t_map *map, int x);
void	raycasting(t_map *map);

/* UTILS */

int		get_color(t_map *map, int x, int y, int i);

/* DRAW */

void	img_pix_put(t_map *map, int x, int y, int color);
void	draw_column(t_map *map, int x);
void	define_texture(t_map *map, int start, int line_height);
int		render(t_map *map);

/* RENDER */

int		create_trgb(int t, int r, int g, int b);
void	render_background(t_map *map);
int		render(t_map *map);

/* MINIMAP */

void	draw_minimap(t_map *map);
void	actualise_minimap(t_map *map, int old_x, int old_y);
void	minimap_pix_put(t_map *map, int x, int y, int color);
void	draw_case(t_map *map, int x, int y, int color);

#endif