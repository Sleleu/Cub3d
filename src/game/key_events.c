/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:42:27 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/28 22:52:51 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    forward(t_map *map)
{
    if (map->map_tab[(int)map->pos_y][(int)(map->pos_x + map->dir_x * map->speed)] != '1')
        map->pos_x += map->dir_x * map->speed;
    if (map->map_tab[(int)(map->pos_y + map->dir_y * map->speed)][(int)map->pos_x] != '1')
        map->pos_y += map->dir_y * map->speed;
}

void    backward(t_map *map)
{
    if (map->map_tab[(int)map->pos_y][(int)(map->pos_x - map->dir_x * map->speed)] != '1')
        map->pos_x -= map->dir_x * map->speed;
    if (map->map_tab[(int)(map->pos_y - map->dir_y * map->speed)][(int)map->pos_x] != '1')
        map->pos_y -= map->dir_y * map->speed;
}

void	left(t_map *map)
{
    if (map->map_tab[(int)map->pos_y][(int)(map->pos_x - map->plane_x * map->speed)] != '1')
        map->pos_x -= map->plane_x * map->speed;
    if (map->map_tab[(int)(map->pos_y - map->plane_y * map->speed)][(int)map->pos_x] != '1')
        map->pos_y -= map->plane_y * map->speed;
}

void	right(t_map *map)
{
    if (map->map_tab[(int)map->pos_y][(int)(map->pos_x + map->plane_x * map->speed)] != '1')
        map->pos_x += map->plane_x * map->speed;
    if (map->map_tab[(int)(map->pos_y + map->plane_y * map->speed)][(int)map->pos_x] != '1')
        map->pos_y += map->plane_y * map->speed;
}

void    rotate(t_map *map, double rot_speed)
{
    double    tmp_dir_x;
    double    tmp_plane_x;

    tmp_dir_x = map->dir_x;
    tmp_plane_x = map->plane_x;
    map->dir_x = map->dir_x * cos(rot_speed) - map->dir_y * sin(rot_speed);
    map->dir_y = tmp_dir_x * sin(rot_speed) + map->dir_y * cos(rot_speed);
    map->plane_x = map->plane_x * cos(rot_speed) - map->plane_y * sin(rot_speed);
    map->plane_y = tmp_plane_x * sin(rot_speed) + map->plane_y * cos(rot_speed);
}

int    key_hook(int keycode, t_map *map)
{
    if (keycode == KEY_ESC)
        close_game(map);
    else if (keycode == KEY_W)
        forward(map);
    else if (keycode == KEY_S)
        backward(map);
    else if (keycode == KEY_A)
        left(map);
    else if (keycode == KEY_D)
        right(map);
    else if (keycode == KEY_LEFT)
        rotate(map, -map->rot_speed);
    else if (keycode == KEY_RIGHT)
        rotate(map, map->rot_speed);
    return (0);
}