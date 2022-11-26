/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:53:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 21:51:31 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
	return (0);
}

void	game_error(t_map *map, char *message)
{
	ft_printf(message);
	free_rgb_texture(map);
	free_double_array(map->map_tab);
	destroy_image(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit (EXIT_FAILURE);
}

void	ft_init_img(t_map *map)
{
	int	w;
	int	h;

	if (!(map->img_no = mlx_xpm_file_to_image(map->mlx, map->north, &w, &h)))
		game_error(map, "Error\nPath to the north texture is incorrect\n");
	if (!(map->img_so = mlx_xpm_file_to_image(map->mlx, map->south, &w, &h)))
		game_error(map, "Error\nPath to the south texture is incorrect\n");
	if (!(map->img_we = mlx_xpm_file_to_image(map->mlx, map->west, &w, &h)))
		game_error(map, "Error\nPath to the west texture is incorrect\n");
	if (!(map->img_ea = mlx_xpm_file_to_image(map->mlx, map->north, &w, &h)))
		game_error(map, "Error\nPath to the east texture is incorrect\n");
}

int	ft_init_game(t_map *map)
{
	if (!(map->mlx = mlx_init())
		|| !(map->mlx_win = mlx_new_window(map->mlx, 1600, 1000, "Cub3D")))
		game_error(map, "Error\nInitialisation of display has failed\n");
	ft_init_img(map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
	mlx_loop(map->mlx);
	return (1);
}