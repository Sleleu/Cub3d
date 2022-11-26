/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:13:33 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 00:36:22 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int error_map(t_map *map)
{
    if (!ft_wall_error(map))
	{
		printf("Error\nMap not closed\n");
		return (1); // faute
	}
    else
        printf("Good MAP\n");
    return (1);
	// if (!ft_form_error(map)
	// 	|| !ft_entity_error(map))
	// 	return (0);
}

void    parse_error(t_map *map, char *message)
{
    //write(2, message, ft_strlen(message));
    if (map->map_tab)
        free_map_tab(map);
    if (map->map_data)
        free_map_data(map);
    if (map->line)
        free(map->line);
    if (map->map_line)
        free(map->map_line);
    exit (write(2, message, ft_strlen(message)));
}

/*
    FIX_SIZE_MAP

    It use set_size_data() to set the heigh and width of the map.
    If they're not defined, it means that more or less than one
    player is placed on the map.
    
    Based on the width, this function resize each line to have
    the same width than the longer line and form a rectangle,
    to make the vertical parsing easier.
*/

void    fix_size_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    set_size_data(map, map->map_tab, i, j);
    if (map->height_map == 0 && map->width_map == 0)
        parse_error(map, "Error\nOnly one player is required on the map\n");
    while (map->map_tab[i])
    {
        if (ft_strlen_cub3d(map->map_tab[i]) <= map->width_map)
        {
            map->map_tab[i] = ft_resize_line(map->map_tab[i], map->width_map);
            if (!map->map_tab[i])
                parse_error(map, "Error\nMalloc error\n");
        }
        printf("%s\n", map->map_tab[i]);
        i++;
    }
    printf("\nwidth map %d, height map %d, player pos x %d, player pos y %d, player direction %c\n",
    map->width_map, map->height_map, map->p_pos_x, map->p_pos_y, map->p_direction);
}

/*
        FT_READ_MAP
    
    read each line in fd, and join them in map_line. 
    At the end, map_line is split with the '/' separator added
    by ft_strjoin_cub3d, and stocked in map_tab.
    if a line is empty, a space is added to count the line in
    ft_split.
    if a '/' is added before the parsing, ft_parse_error is called
    to free and exit the program properly.
*/

void	ft_read_map(int fd, t_map *map)
{
	while (42)
	{
		map->line = get_next_line(fd);
		if (!map->line)
            break ;
        if (map->line[0] == '\n')
            map->line[0] = ' ';
        if (ft_strchr(map->line, '/'))
            parse_error(map, "Error\nInvalid character in map\n");
		map->map_line = ft_strjoin_cub3d(map->map_line, map->line);
		free(map->line);
	}
	map->map_tab = ft_split(map->map_line, '/');
    free(map->map_line);
    map->map_line = NULL;
    fix_size_map(map);
}

int ft_parse_map(t_map *map, int fd)
{
    ft_read_map(fd, map);
  //  get_map_stat(map);
    if (error_map(map))
        return (0);
    close(fd);

    return (1);
}
