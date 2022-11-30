/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:06:46 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/01 00:08:01 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	minimap_pix_put(t_map *map, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > map->display_height - 1 || x < 0
		|| x > map->display_width - 1)
		return ;
	pixel = (map->minimap.addr + (y * map->minimap.line_len
				+ x * (map->minimap.bpp / 8)));
	*(int *)pixel = color;
}

void	draw_case(t_map *map, int x, int y, int color)
{
	int i = 0;
	int j = 0;

	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			minimap_pix_put(map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_map *map)
{
	// for (int i = 0; map->map_tab[i]; i++)
	// {
	// 	for (int j = 0; map->map_tab[i][j]; j++)
	// 	{
	// 		if (map->map_tab[i][j] == '1')
	// 			draw_case(map, j * 10, i * 10, 200200200);
	// 		else if (map->map_tab[i][j] == '0')
	// 			draw_case(map, j * 5, i * 5, 100100100);
			
	// 	}
	// }
	(void)map;
	//mlx_put_image_to_window(map->mlx, map->mlx_win, map->minimap.mlx_img, 10, 10);
}
