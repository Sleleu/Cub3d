/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:42:27 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/28 20:47:56 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    clean_screen(t_map *map)
{
    int i = 0;
    int j = 0;

    while (i < map->display_width)
    {
        j = 0;
        while (j < map->display_height)
        {
            mlx_pixel_put(map->mlx, map->mlx_win, i, j, 0000000000);
            j++;
        }
        i++;
    }
}

void    forward(t_map *map)
{
    // clean_screen(map);
    if (map->map_tab[(int)map->pos_y][(int)(map->pos_x + map->dir_x * map->speed)] != '1')
        map->pos_y += map->dir_x * map->speed;
    if (map->map_tab[(int)(map->pos_y + map->dir_y * map->speed)][(int)map->pos_x] != '1')
        map->pos_y += map->dir_y * map->speed;
    // render(map);
}

void    backward(t_map *map)
{
    // clean_screen(map);
    if (map->map_tab[(int)map->pos_y][(int)(map->pos_x - map->dir_x)] != '1')
        map->pos_y -= map->dir_x * map->speed;
    if (map->map_tab[(int)(map->pos_y + map->dir_y - map->speed)][(int)map->pos_x] != '1')
        map->pos_y -= map->dir_y * map->speed;
    // render(map);
}

void    rotate(t_map *map, double rot_speed)
{
    double    tmp_dir_x;
    double    tmp_plane_x;

    // clean_screen(map);
    tmp_dir_x = map->dir_x;
    tmp_plane_x = map->plane_x;
    map->dir_x = map->dir_x * cos(rot_speed) - map->dir_y * sin(rot_speed);
    map->dir_y = tmp_dir_x * sin(rot_speed) + map->dir_y * cos(rot_speed);
    map->plane_x = map->plane_x * cos(rot_speed) - map->plane_y * sin(rot_speed);
    map->plane_y = tmp_plane_x * sin(rot_speed) + map->plane_y * cos(rot_speed);
    // render(map);
}

int    key_hook(int keycode, t_map *map)
{
    if (keycode == KEY_ESC)
        close_game(map);
    else if (keycode == KEY_W)
        forward(map);
    else if (keycode == KEY_S)
        backward(map);
    // else if (keycode == KEY_A)
    //     left(map);
    // else if (keycode == KEY_D)
    //     right(map);
    else if (keycode == KEY_LEFT)
        rotate(map, -map->rot_speed);
    else if (keycode == KEY_RIGHT)
        rotate(map, map->rot_speed);
    return (0);
}