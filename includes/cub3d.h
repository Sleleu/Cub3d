/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:50:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 16:53:14 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <mlx.h>
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


// MAIN

void    bzero_struct(t_map *map);
int		ft_test_file(char *argv);

// FREE_FUNCTIONS

void	free_map_tab(t_map *map);
void	free_map_data(t_map *map);
int		close_game(t_map *map);

// PARSE

void    parse_error(t_map *map, char *message);
int		is_valid_char(char c, char *valid_char);
void    ft_read_map(int fd, t_map *map);
int     ft_parse_map(t_map *map, int fd);

// WALL_ERROR

int		check_column(char **column, int y, int x, int size_y);
int		vertical_check(t_map *map, int y, int x, int size_y);
int		check_line(char *line, int x);
int		horizontal_check(t_map *map, int y, int x);
int		ft_wall_error(t_map *map);

// INIT_GAME

void    ft_init_game(t_map *map);

#endif