/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:31:28 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 16:20:56 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_column(char **column, int y, int x, int size_y)
{
	while (y < size_y)
	{
		//printf("y = %d x = %d char = %c\n", y, x, column[y][x]);
		if (y == 0 && !is_valid_char(column[y][x], "1 "))
			return (0);
		if (!is_valid_char(column[y][x], "10NSEW "))
			return (0);
		if (column[y][x] == ' ')
		{
			if (y > 0 && column[y - 1][x] != '1')
				return (0);
			while (y < size_y && column[y][x] == ' ')
			{
				//printf("0 | ");
				y++;
			}
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

int	vertical_check(t_map *map, int y, int x, int size_y)
{
	//printf("YOOOOOOO size_y = %d\n\n\n", size_y);
	while (map->map_tab[y][x])
	{
		if (!check_column(map->map_tab, y, x, size_y))
			return (0);
		x++;
	}
	return (1);	
}

int check_line(char *line, int x)
{
	while (line[x])
	{
		if (x == 0 && !is_valid_char(line[x], "1 "))
			return (0);
		if (!is_valid_char(line[x], "10NSEW "))
			return (0);
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
		if (!check_line(map->map_tab[y], x))
			return (-1);
		y++;
	}
	return (y);
}

int	ft_wall_error(t_map *map)
{
	int y;
	int size_y;
	int x;
	
	y = 0;
	x = 0;
	size_y = horizontal_check(map, y, x);
	if (size_y == -1)
		return (0);
	//printf("\n\n y = %d x = %d size_y = %d\n", y, x, size_y);
	if (!vertical_check(map, y, x, size_y))
		return (0);
	return (1);
}
