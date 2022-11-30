/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:34:10 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/30 17:57:17 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	img_pix_put(t_map *map, int x, int y, int color)
{
	char	*pixel;
	// t_img	img;

	// img = map->img;
	if (y < 0 || y > map->display_height - 1 || x < 0 || x > map->display_width - 1)
		return ;
	pixel = map->img[4].addr + (y * map->img[4].line_len + x * (map->img[4].bpp / 8));
	*(int *)pixel = color;
}

void	img_pix_put_wall(t_map *map, int x, int y, int color)
{
	char	*pixel;
	// t_img	img;

	// img = map->img;
	if (y < 0 || y > map->display_height - 1 || x < 0 || x > map->display_width - 1)
		return ;
	pixel = map->img[1].addr + (y * map->img[1].line_len + x * (map->img[1].bpp / 8));
	*(int *)pixel = color;
}

int	get_color(t_map *map, int x, int y)
{
	if (y < 0 || y > map->display_height - 1 || x < 0 || x > map->display_width - 1)
		return 0;
	return (*(int *)(map->img[1].addr + 
			(y * map->img[1].line_len + x * (map->img[1].bpp / 8))));
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

void	define_texture(t_map *map)
{
	map->tex_num = map->map_tab[map->map_y][map->map_x] - 1;
	if (map->wall_side == 0)
		map->wall_x = map->pos_y + map->perpwalldist * map->ray_dir_y;
	else
		map->wall_x = map->pos_x + map->perpwalldist * map->ray_dir_x;
	map->tex_x = map->wall_x * 128; // <-- text_width
	if (map->wall_side == 0 && map->ray_dir_x > 0)
		map->tex_x = 128 - map->tex_x - 1;
	if (map->wall_side == 1 && map->ray_dir_y < 0)
		map->tex_x = 128 - map->tex_x - 1;
}

void	draw_column(t_map *map, int x)
{
	int	start;
	int end;
	int line_height;
	int color;

	map->tex_y++;
	if (map->tex_y == map->display_height)
		map->tex_y = 0;
	define_column(map, &line_height, &start, &end);
	define_texture(map);
	while (start < end)
	{
		color = get_color(map, map->img[1].w, map->img[1].h);
		if (map->wall_side == 1)
		{
			//mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_no, x, start);
			img_pix_put(map, x, start, 200200200);
			//img_pix_put_wall(map, map->img[1].w, map->img[1].h, color);
		}
		else
			img_pix_put(map, x, start, 100100100);
		start++;
	}
}