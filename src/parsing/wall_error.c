/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:31:28 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 22:29:39 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_column(char **column, int y, int x, int size_y)
{
	while (y < size_y)
	{
		if (y == 0 && !is_valid_char(column[y][x], "1 "))
			return (0);
		if (!is_valid_char(column[y][x], "10NSEW "))
			return (0);
		if (column[y][x] == ' ')
		{
			if (y > 0 && column[y - 1][x] != '1')
				return (0);
			while (y < size_y && column[y][x] == ' ')
				y++;
			if (y < size_y && column[y][x] != '1')
				return (0);
		}
		if (y < size_y)
			y++;
	}
	if (!is_valid_char(column[y - 1][x], "1 "))
		return (0);
	return (1);
}

int	vertical_check(t_map *map, int y, int x)
{
	while (map->map_tab[y][x])
	{
		if (!check_column(map->map_tab, y, x, map->height_map))
			return (0);
		x++;
	}
	return (1);
}

int	check_line(t_map *map, char *line, int x)
{
	while (line[x])
	{
		if (x == 0 && !is_valid_char(line[x], "1 "))
			return (0);
		if (!is_valid_char(line[x], "10NSEW "))
			parse_error(map, "Error\nInvalid character on map\n");
		if (line[x] == ' ')
		{
			if (x > 0 && line[x - 1] != '1')
				return (0);
			while (line[x] && line[x] == ' ')
				x++;
			if (line[x] && line[x] != '1')
				return (0);
		}
		if (line[x])
			x++;
	}
	if (!is_valid_char(line[x - 1], "1 "))
		return (0);
	return (1);
}

int	horizontal_check(t_map *map, int y, int x)
{
	while (map->map_tab[y])
	{
		if (!check_line(map, map->map_tab[y], x))
			return (0);
		y++;
	}
	return (1);
}

int	ft_wall_error(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!horizontal_check(map, y, x) || !vertical_check(map, y, x))
	{
		free_rgb_texture(map);
		return (0);
	}
	return (1);
}
