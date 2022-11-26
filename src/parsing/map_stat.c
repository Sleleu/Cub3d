/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:48:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 18:11:01 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	ASSIGN_PLAYER_POS
	
	When a char E/N/S/W is found during the parsing,
	the position and direction of the player is stocked in the structure.
*/

void    assign_player_pos(t_map *map, char direction, int i, int j)
{
    map->p_pos_y = i;
    map->p_pos_x = j;
    map->p_direction = direction;
}

/*
    SET_SIZE_DATA
    
    2 loops to get the height and width of the map, based on
    the longer line in the array.
    The player position and direction is found during the
    loop, and if there is more than one player, set_size_data
    don't set the height and width of the map.
*/

void    set_size_data(t_map *map, char **array, int i, int j)
{
    int tmp;
    int count_player;

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

void	get_texture_path(t_map *map, char **path, char **split_line)
{
	int i;
	
	i = 0;
	while (split_line[i])
		i++;
	if (i == 3 && split_line[2][0] == '\n')
		free(split_line[i--]);
	if (i != 2)
	{
		free(split_line);
		parse_error(map, "Error\nTexture line is incorrect\n");
	}
	*path = ft_strjoin_cub3d(*path, split_line[1]);
	free(split_line);
}

int	ft_strlen_rgb(char *line)
{
	int i;

	i = 0;
	while (line && line[i] && line[i] != 32 && line[i] != '\n')
		i++;
	return (i);
}

int	parse_rgb_line(char *line)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	if (!ft_isdigit(line[0]) || !ft_isdigit(line[ft_strlen_cub3d(line) - 1])
		|| ft_strlen_rgb(line) > 11)
		return (0);
	while (line[i + 1])
	{
		if (line[i] == ',')
			comma++;
		else if ((!ft_isdigit(line[i])) && line[i] != ',')
			return (0);
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

int	check_rgb(t_map *map, int *rgb, char *line)
{
	int i;
	int	j;
	
	j = 1;
	i = 0;
	if (!parse_rgb_line(line))
		parse_error(map, "Error\nBad character in rgb line\n");
	while (line[i])
	{
		if (i == 0)
			rgb[0] = ft_atoi(line);
		else if (j == 1)
			rgb[1] = ft_atoi(line + i + 1);
		else if (j == 2)
			rgb[2] = ft_atoi(line + i + 1);
		if (line[i] == ',')
			j++;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("rgb %d %d\n", i, rgb[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

void	get_rgb(t_map *map, int *rgb, char **split_line)
{
	int i;
	
	i = 0;
	while (split_line[i])
		i++;
	if (i == 3 && split_line[2][0] == '\n')
		free(split_line[i--]);
	if ((i != 2) || !check_rgb(map, rgb, split_line[1]))
	{
		free(split_line);
		parse_error(map, "Error\nRGB line is incorrect\n");
	}
	free(split_line);
}

void	check_stat(t_map *map)
{
	int i;
	
	i = 0;
	if (!map->north || !map->south || !map->east || !map->west)
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
	static int i = 0;

	while (i < 6)
	{
		if (line[0] == ' ' && !line[1])
			return (0);
		if (!ft_strncmp(line, "NO ", 3))
			get_texture_path(map, &map->north, ft_split(line, ' '));
		else if (!ft_strncmp(line, "SO ", 3))
			get_texture_path(map, &map->south, ft_split(line, ' '));
		else if (!ft_strncmp(line, "WE ", 3))
			get_texture_path(map, &map->west, ft_split(line, ' '));
		else if (!ft_strncmp(line, "EA ", 3))
			get_texture_path(map, &map->east, ft_split(line, ' '));
		else if (!ft_strncmp(line, "F ", 2))
			get_rgb(map, map->rgb_floor, ft_split(line, ' '));
		else if (!ft_strncmp(line, "C ", 2))
			get_rgb(map, map->rgb_sky, ft_split(line, ' '));
		else
			parse_error(map, "Error\nIncorrect data on texture/color");
		i++;
		return (0);
	}
	printf("nord %s\n sud %s\n est %s\n ouest %s\n",
	map->north, map->south, map->east, map->west);
	for (int j = 0; j < 3; j++)
		printf("rgb sky %d | rgb floor %d\n", map->rgb_sky[j], map->rgb_floor[j]);
	check_stat(map);
	return (1);
}