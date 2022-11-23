/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:08:16 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/23 20:29:06 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int close_game(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
    exit (0);
}

int key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
    return (0);
}

void    ft_init_game(t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, 800, 600, "Cub3D");
    mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
    mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
    mlx_loop(map->mlx);
}

int main(int ac, char **av)
{
    t_map   map;
    int     fd;

    (void)ac;
    (void)av;
    fd = open(av[1], O_RDONLY);
    if (fd <= 0)
    {
        write(2, "Error\nFailed to open file\n", 27);
    }
    ft_parse_map(&map, fd);
    ft_init_game(&map);
    return (0);
}