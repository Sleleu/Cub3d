/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:34:10 by sleleu            #+#    #+#             */
/*   Updated: 2023/01/02 17:14:01 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	img_pix_put(t_map *map, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > map->display_height - 1 || x < 0
		|| x > map->display_width - 1)
		return ;
	pixel = (map->img[4].addr + (y * map->img[4].line_len
				+ x * (map->img[4].bpp / 8)));
	*(int *)pixel = color;
}

void	define_column(t_map *map, int *line_height, int *start, int *end)
{
	*line_height = map->display_height / map->perpwalldist;
	*start = -*line_height / 2 + map->display_height / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + map->display_height / 2;
	if (*end >= map->display_height)
		*end = map->display_height - 1;
}

void	define_texture(t_map *map, int start, int line_height)
{
	if (map->wall_side == 0)
		map->wall_x = map->pos_y + map->perpwalldist * map->ray_dir_y;
	else
		map->wall_x = map->pos_x + map->perpwalldist * map->ray_dir_x;
	map->wall_x -= floor(map->wall_x);
	map->tex_x = map->wall_x * 128;
	if (map->wall_side == 0 && map->ray_dir_x > 0)
		map->tex_x = 128 - map->tex_x - 1;
	if (map->wall_side == 1 && map->ray_dir_y < 0)
		map->tex_x = 128 - map->tex_x - 1;
	map->step = 1.0 * 128 / line_height;
	map->tex_pos = (start - map->display_height / 2
			+ line_height / 2) * map->step;
}

void	draw(t_map *map, int x, int texture)
{
	int	color;

	color = get_color(map, map->tex_x, map->tex_y, texture);
	img_pix_put(map, x, map->start, color);
}

void	draw_column(t_map *map, int x)
{
	int	line_height;

	define_column(map, &line_height, &map->start, &map->end);
	define_texture(map, map->start, line_height);
	while (map->start < map->end)
	{
		map->tex_y = (int)map->tex_pos & (128 - 1);
		map->tex_pos += map->step;
		if (map->wall_side == 1 && map->ray_dir_y < 0)
			draw(map, x, SOUTH);
		else if (map->wall_side == 1 && map->ray_dir_y > 0)
			draw(map, x, NORTH);
		else if (map->wall_side == 0 && map->ray_dir_x < 0)
			draw(map, x, WEST);
		else if (map->wall_side == 0 && map->ray_dir_x > 0)
			draw(map, x, EAST);
		map->start++;
	}
}
