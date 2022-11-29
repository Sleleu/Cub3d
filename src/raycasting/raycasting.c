/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:40:00 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/29 16:28:55 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_delta_dist(t_map *map)
{	
	if (map->ray_dir_x == 0)
		map->delta_dist_x = INT_MAX;
	else
		map->delta_dist_x = fabs(1 / map->ray_dir_x);
	if (map->ray_dir_y == 0)
		map->delta_dist_y = INT_MAX;
	else
		map->delta_dist_y = fabs(1 / map->ray_dir_y);	
}

void	get_step(t_map *map)
{
	if (map->ray_dir_x < 0)
	{
		map->step_x = -1;
		map->side_dist_x = (map->pos_x - map->map_x) * map->delta_dist_x;
	}
	else
	{
		map->step_x = 1;
		map->side_dist_x = (map->map_x + 1.0 - map->pos_x) * map->delta_dist_x;
	}
	if (map->ray_dir_y < 0)
	{
		map->step_y = -1;
		map->side_dist_y = (map->pos_y - map->map_y) * map->delta_dist_y;
	}
	else
	{
		map->step_y = 1;
		map->side_dist_y = (map->map_y + 1.0 - map->pos_y) * map->delta_dist_y;
	}
}

void	digital_differential_analyser(t_map *map)
{
	int wall;


	wall = 0;
	while (wall == 0)
	{
		if (map->side_dist_x < map->side_dist_y)
		{
			map->side_dist_x += map->delta_dist_x;
			map->map_x += map->step_x;
			map->wall_side = 0; // savoir le cote du mur
		}
		else
		{
			map->side_dist_y += map->delta_dist_y;
			map->map_y += map->step_y;
			map->wall_side = 1;
		}
		if (map->map_tab[map->map_y][map->map_x] == '1')
			wall = 1; // le rayon touche un mur
		// printf("mapY %d map_X %d\n", map->map_y, map->map_x);
		// printf("\nsideX %f, sideY %f deltaX %f deltaY %f\n", map->side_dist_x, map->side_dist_y, map->delta_dist_x, map->delta_dist_y);
		// printf("\nCHARACTER %c\n", map->map_tab[map->map_y][map->map_x]);
		// sleep(1);
	}
}

void	init_raycasting(t_map *map, int x)
{
	map->map_x = (int)map->pos_x;
	map->map_y = (int)map->pos_y;
	map->cam_x = 2 * x / (double)map->display_width - 1;
	map->ray_dir_x = map->dir_x + map->plane_x * map->cam_x;
	map->ray_dir_y = map->dir_y + map->plane_y * map->cam_x;
	// printf("ray_dir_x %f, ray_dir_y %f | cam_x %f | plane X %f plane Y %f\n", 
	// map->ray_dir_x, map->ray_dir_y, map->cam_x, map->plane_x, map->plane_y;
}

void	raycasting(t_map *map)
{
	int x;

	x = 0;
	while (x < map->display_width)
	{
		init_raycasting(map, x);
		get_delta_dist(map);
		get_step(map);
		digital_differential_analyser(map);
		if (map->wall_side == 0)
			map->perpwalldist = ((map->side_dist_x - map->delta_dist_x));
		else
			map->perpwalldist = ((map->side_dist_y - map->delta_dist_y));
		// printf("perpwalldist %f, side_dist_x %f delta_dist %f\n", map->perpwalldist, map->side_dist_x, map->delta_dist_x);
		draw_column(map, x);
		x++;
		// printf("x = %d | perpwalldist = %f | side_dist_y %f | delta_dist_y %f\n", x, map->perpwalldist, map->side_dist_y, map->delta_dist_y);
	}	
}