/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:34:10 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/28 17:52:00 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_column(t_map *map, int line_height, int x)
{
	int	start;
	int end;
	
	start = -line_height / 2 + map->display_height / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + map->display_height / 2;
	if (end >= map->display_height)
		end = map->display_height - 1;
	while (start < end)
	{
		if (map->wall_side == 1)
			mlx_pixel_put(map->mlx, map->mlx_win, x, start, 200200200);
		else
			mlx_pixel_put(map->mlx, map->mlx_win, x, start, 100100100);
		start++;
	}
}