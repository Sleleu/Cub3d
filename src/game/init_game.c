/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:53:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 16:55:38 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
    return (0);
}

void    ft_init_game(t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, 1200, 800, "Cub3D");
    mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
    mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
    mlx_loop(map->mlx);
}