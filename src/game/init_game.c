/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:53:51 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/29 15:15:10 by sleleu           ###   ########.fr       */
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

t_map	ft_init_game_stat(t_map map)
{
	map.speed = 0.10;
    map.rot_speed = 0.07;
	map.display_width = 1280;
	map.display_height = 1024;
	if (map.direction == 'N')
	{
		map.plane_x = 0.66;
		map.plane_y = 0;
	}
	if (map.direction == 'S')
	{
		map.plane_x = -0.66;
		map.plane_y = 0;
	}
	if (map.direction == 'W')
	{
		map.plane_x = 0;
		map.plane_y = 0.66;
	}
	if (map.direction == 'E')
	{
		map.plane_x = 0;
		map.plane_y = -0.66;
	}
	return (map);
}

void	render_background(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->display_width)
	{
		y = 0;
		while (y < map->display_height)
		{
			if (y < map->display_height / 2)
				img_pix_put(map, x, y, 0x0d9dff);
			else
				img_pix_put(map, x, y, 0x4d4d4d);
			y++;
		}
		++x;
	}
}

int		render(t_map *map)
{
	render_background(map);
	raycasting(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.mlx_img, 0, 0);
	return (0);
}

int	ft_init_game(t_map *map)
{
	t_map data;

	data = *map;
	data = ft_init_game_stat(data);
	data.mlx = mlx_init();
	if (!data.mlx)
		game_error(&data, "Error\nInitialisation of display has failed\n");
	data.mlx_win = mlx_new_window(data.mlx, data.display_width, data.display_height, "Cub3D");
	if (!data.mlx_win)
		game_error(&data, "Error\nInitialisation of window has failed\n");
	data.img.mlx_img = mlx_new_image(data.mlx, data.display_width, data.display_height);
	if (!data.img.mlx_img)
		game_error(&data, "Error\nErreur jtai dis\n");
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// render(&data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, close_game, &data);
	mlx_loop(data.mlx);
	return (0);
}

// int	ft_init_game(t_map *map)
// {
// 	ft_init_game_stat(map);
// 	map->mlx = mlx_init();
// 	if (!map->mlx)
// 		game_error(map, "Error\nInitialisation of display has failed\n");
// 	if (!map->mlx_win)
// 		game_error(map, "Error\nInitialisation of window has failed\n");
// 	ft_init_img(map);
// 	raycasting(map);
// 	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
// 	mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
// 	mlx_loop(map->mlx);
// 	return (1);
// }
