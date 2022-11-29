/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:34:10 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/29 14:27:03 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	img_pix_put(t_map *map, int x, int y, int color)
{
	char	*pixel;
	t_img	img;

	img = map->img;
	if (y < 0 || y > map->display_height - 1 || x < 0 || x > map->display_width - 1)
		return ;
	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(int *)pixel = color;
}

void	draw_column(t_map *map, int x)
{
	int	start;
	int end;
	int line_height;
	
	line_height = map->display_height / map->perpwalldist;
	start = -line_height / 2 + map->display_height / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + map->display_height / 2;
	if (end >= map->display_height)
		end = map->display_height - 1;
	while (start < end)
	{
		if (map->wall_side == 1)
			img_pix_put(map, x, start, 300200200);
		else
			img_pix_put(map, x, start, 100100100);
		start++;
	}
}