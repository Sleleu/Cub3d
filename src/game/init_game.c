/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:53:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/01 00:41:35 by sleleu           ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < 4)
	{
		map->img[i].mlx_img = mlx_xpm_file_to_image(map->mlx, map->img[i].path,
				&map->img[i].w, &map->img[i].h);
		if (!map->img[i].mlx_img)
			game_error(map, "Error\nPath texture is incorrect\n");
		i++;
	}
	map->img[4].mlx_img = mlx_new_image(map->mlx,
			map->display_width, map->display_height);
	if (!map->img[4].mlx_img)
		game_error(map, "Error\nImage initialisation has failed\n");
	i = 0;
	while (i < 5)
	{
		map->img[i].addr = mlx_get_data_addr(map->img[i].mlx_img,
				&map->img[i].bpp, &map->img[i].line_len, &map->img[i].endian);
		if (!map->img[i].addr)
			game_error(map, "Error\nImage initialisation has failed\n");
		i++;
	}
}

void	ft_init_game_stat(t_map *map)
{
	map->speed = 0.09;
	map->rot_speed = 0.09;
	map->display_width = 1940;
	map->display_height = 1280;
	if (map->direction == 'N')
	{
		map->plane_x = 0.66;
		map->plane_y = 0;
	}
	if (map->direction == 'S')
	{
		map->plane_x = -0.66;
		map->plane_y = 0;
	}
	if (map->direction == 'W')
	{
		map->plane_x = 0;
		map->plane_y = 0.66;
	}
	if (map->direction == 'E')
	{
		map->plane_x = 0;
		map->plane_y = -0.66;
	}
}

void	init_minimap(t_map *map)
{
	map->minimap.mlx_img = mlx_new_image(map->mlx, map->width_map * 7, map->height_map * 7);
	if (!map->minimap.mlx_img)
		game_error(map, "Error\nMinimap creation has failed\n"); //DETRUIRE IMAGE DE MINIMAP
	map->minimap.addr = mlx_get_data_addr(map->minimap.mlx_img, &map->minimap.bpp, &map->minimap.line_len, &map->minimap.endian);
	if (!map->minimap.addr)
		game_error(map, "Error\nMinimap creation has failed\n"); //DETRUIRE IMAGE DE MINIMAP
	for (int i = 0; map->map_tab[i]; i++)
	{
		for (int j = 0; map->map_tab[i][j]; j++)
		{
			if (map->map_tab[i][j] == '1')
				draw_case(map, j * 7, i * 7, 0x000000);
			else if (map->map_tab[i][j] == '0')
				draw_case(map, j * 7, i * 7, 0x660000);
			else if (is_valid_char(map->map_tab[i][j], "NSEW"))
				draw_case(map, j * 7, i * 7, 0xEEEE20);
			else
				draw_case(map, j * 7, i * 7, 0x050505);
		}
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
	init_minimap(map);
	mlx_loop_hook(map->mlx, &render, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
	mlx_loop(map->mlx);
	return (0);
}
