/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:50:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/28 15:40:47 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <mlx.h>
#include <math.h>
#include "struct.h"
#include "../libft/libft.h"

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363


/* ********************************************************** */
/*                           MAIN                             */
/* ********************************************************** */

/* MAIN */

void    bzero_struct(t_map *map);
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

void    parse_error(t_map *map, char *message);
void    ft_read_map(int fd, t_map *map);
int     ft_parse_map(t_map *map, int fd);

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

void    assign_player_pos(t_map *map, char direction, int i, int j);
void    set_size_data(t_map *map, char **array, int i, int j);
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

/* INIT_GAME */

void	game_error(t_map *map, char *message);
void	ft_init_game_stat(t_map *map);
void	ft_init_img(t_map *map);
int		ft_init_game(t_map *map);

/* ********************************************************** */
/*                           RAYCASTING                       */
/* ********************************************************** */

/* UTILS */

double convert_degree_radians(int degree);

void	raycasting(t_map *map);

/* DRAW */

void	draw_column(t_map *map, int line_height, int x);

#endif