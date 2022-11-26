/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:34:22 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 21:18:04 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_image(t_map *map)
{
	if (map->mlx)
	{
		if (map->img_no)
			mlx_destroy_image(map->mlx, map->img_no);
		if (map->img_so)
			mlx_destroy_image(map->mlx, map->img_so);
		if (map->img_we)
			mlx_destroy_image(map->mlx, map->img_we);
		if (map->img_ea)
			mlx_destroy_image(map->mlx, map->img_ea);
	}		
}

void	free_rgb_texture(t_map *map)
{
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
}

void	free_double_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int close_game(t_map *map)
{
	free_rgb_texture(map);
    free_double_array(map->map_tab);
	destroy_image(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
    free(map->mlx);
    exit (0);
}
