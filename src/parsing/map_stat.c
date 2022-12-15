/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:48:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/15 15:05:17 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	ASSIGN_PLAYER_POS
	
	When a char E/N/S/W is found during the parsing,
	the position and direction of the player is stocked in the structure.
*/

void	assign_player_pos(t_map *map, char direction, int i, int j)
{
	map->pos_y = (double)i;
	map->pos_x = (double)j;
	map->p_dir = direction;
	if (direction == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
	}
	else if (direction == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
	}
	else if (direction == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
	}
	else if (direction == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
	}
}

/*
    SET_SIZE_DATA
    
    2 loops to get the height and width of the map, based on
    the longer line in the array.
    The player position and direction is found during the
    loop, and if there is more than one player, set_size_data
    don't set the height and width of the map.
*/

void	set_size_data(t_map *map, char **array, int i, int j)
{
	int	tmp;
	int	count_player;

	tmp = 0;
	count_player = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (is_valid_char(array[i][j], "NSEW"))
			{
				assign_player_pos(map, array[i][j], i, j);
				count_player++;
			}
			j++;
		}
		if (j > tmp)
			tmp = j;
		i++;
	}
	if (count_player != 1)
		return ;
	map->width_map = tmp;
	map->height_map = i;
}

void	check_stat(t_map *map)
{
	int	i;

	i = 0;
	if (!map->img[0].path || !map->img[1].path
		|| !map->img[2].path || !map->img[3].path)
		parse_error(map, "Error\nMissing textures\n");
	while (i < 3)
	{
		if (map->rgb_floor[i] == -1 || map->rgb_sky[i] == -1)
			parse_error(map, "Error\nMissing colors\n");
		i++;
	}
}

int	get_map_stat(t_map *map, char *line)
{
	static int	i = 0;

	while (i < 6)
	{
		if (line[0] == ' ' && !line[1])
			return (0);
		if (!ft_strncmp(line, "NO ", 3))
			get_texture_path(map, &map->img[0].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "SO ", 3))
			get_texture_path(map, &map->img[1].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "WE ", 3))
			get_texture_path(map, &map->img[2].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "EA ", 3))
			get_texture_path(map, &map->img[3].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "F ", 2))
			get_rgb(map, map->rgb_floor, ft_split(line, ' '));
		else if (!ft_strncmp(line, "C ", 2))
			get_rgb(map, map->rgb_sky, ft_split(line, ' '));
		else
			parse_error(map, "Error\nIncorrect data on texture/color\n");
		i++;
		return (0);
	}
	check_stat(map);
	return (1);
}
