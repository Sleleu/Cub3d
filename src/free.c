/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:34:22 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 16:36:41 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map_tab(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_tab[i])
	{
		free(map->map_tab[i]);
		i++;
	}
	free(map->map_tab);
}

void	free_map_data(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_data[i])
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
}	

int close_game(t_map *map)
{
    free_map_tab(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
    free(map->mlx);
    exit (0);
}
