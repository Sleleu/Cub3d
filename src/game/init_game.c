/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:53:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/27 23:49:54 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

	map->img_no = mlx_xpm_file_to_image(map->mlx, map->north, &w, &h);
	if (!map->img_no)
		game_error(map, "Error\nPath to the north texture is incorrect\n");
	map->img_so = mlx_xpm_file_to_image(map->mlx, map->south, &w, &h);
	if (!map->img_so)
		game_error(map, "Error\nPath to the south texture is incorrect\n");
	map->img_we = mlx_xpm_file_to_image(map->mlx, map->west, &w, &h);
	if (!map->img_we)
		game_error(map, "Error\nPath to the west texture is incorrect\n");
	map->img_ea = mlx_xpm_file_to_image(map->mlx, map->north, &w, &h);
	if (!map->img_ea)
		game_error(map, "Error\nPath to the east texture is incorrect\n");
}

void	ft_init_game_stat(t_map *map)
{
	map->map_x = (int)map->pos_x;
	map->map_y = (int)map->pos_y;
	map->display_width = 1280;
	map->display_height = 1024;
	if (map->direction == 'N')
	{
		map->plane_x = 0;
		map->plane_y = 0.66;
	}
	if (map->direction == 'S')
	{
		map->plane_x = 0;
		map->plane_y = -0.66;
	}
	if (map->direction == 'W')
	{
		map->plane_x = -0.66;
		map->plane_y = 0;
	}
	if (map->direction == 'E')
	{
		map->plane_x = 0.66;
		map->plane_y = 0;
	}
}

int	ft_init_game(t_map *map)
{
	ft_init_game_stat(map);
	map->mlx = mlx_init();
	if (!map->mlx)
		game_error(map, "Error\nInitialisation of display has failed\n");
	map->mlx_win = mlx_new_window(map->mlx, map->display_width,
			map->display_height, "Cub3D");
	if (!map->mlx_win)
		game_error(map, "Error\nInitialisation of window has failed\n");
	ft_init_img(map);
	raycasting(map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
	mlx_loop(map->mlx);
	return (1);
}
