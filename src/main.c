/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:08:16 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 16:54:01 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_test_file(char *argv)
{
	int		fd;
	char	test[1];

	fd = open(argv, O_RDONLY);
	if (!read(fd, test, 1))
	{
		write(2, "Error\nEmpty file\n", 18);
		return (0);
	}
	close(fd);
	return (1);
}

void    bzero_struct(t_map *map)
{
    int i;

    i = 0;
    map->map_tab = NULL;
    map->map_data = NULL;
    map->width_map = 0;
    map->height_map = 0;
    map->p_pos_x = 0;
    map->p_pos_y = 0;
    map->p_direction = '\0';
    while (i < 3)
    {
        map->rgb_floor[i] = 0;
        map->rgb_sky[i] = 0;
        i++;
    }
}

int main(int ac, char **av)
{
    t_map   map;
    int     fd;

    bzero_struct(&map);
    if (ac != 2)
        parse_error(&map, "Error\nOne argument required\n");
	if (!ft_test_file(av[1]))
		return (1);
    fd = open(av[1], O_RDONLY);
    if (fd <= 0)
    {
        write(2, "Error\nFailed to open file\n", 27);
        return (37);
    }
    if (!ft_parse_map(&map, fd))
    {
        free_map_tab(&map);
        return (38);
    }
    ft_init_game(&map);
    return (0);
}