/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:34:22 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/29 19:03:45 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_image(t_map *map)
{
	int	i;

	i = 0;
	if (map->mlx)
	{
		while (i < 4)
		{
			if (map->img[i].mlx_img)
				mlx_destroy_image(map->mlx, map->img[i].mlx_img);
			i++;
		}
	}		
}

void	free_rgb_texture(t_map *map)
{
	if (map->img[0].path)
		free(map->img[0].path);
	if (map->img[1].path)
		free(map->img[1].path);
	if (map->img[2].path)
		free(map->img[2].path);
	if (map->img[3].path)
		free(map->img[3].path);
}

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	close_game(t_map *map)
{
	free_rgb_texture(map);
	free_double_array(map->map_tab);
	destroy_image(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit (0);
}
