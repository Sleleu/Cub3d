/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:13:33 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 17:49:49 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//espaces de fin a traiter

/*
int ft_check_space(char *str, int j)
{
    if (j > 0 && str[j - 1] != '1')
        return (-1);
    while (str[j] && str[j] == 32)
        j++;
    // Si espace a la fin ca crash 
    if (str[j] && str[j] != '1')
        return (-2);
    return (j);
}

int ft_check_border(char *str)
{
    int j;

    printf("str = %s\n", str);
    j = 0;
	while (str[j])
	{
        if (str[j] == 32)
        {
            j = ft_check_space(str, j);
            printf("check space = %d\n", j);
            if (j < 0)
                return (-1);
        }
		if (str[j] != '1')
	    	return (-1);
        // Possibilite de segfault
        j++;
	}
    return (1);
}

int ft_check_line(char *str)
{
    int i;

    i = 0;
    printf("str = %s\n", str);
    if (str[i] == 32)
    {
        i = ft_check_space(str, i);
        if (i == -1)
            return (-1);
    }
    if (str[i] != '1')
        return (-1);
    while (str[i])
    {
        if (str[i] == 32)
        {
            i = ft_check_space(str, i);
            printf("checkspace = %d, i = %d, str[%d] = %c", i, i, i, str[i]);
            if (i == -1)
                return (-1);
        }
        i++;
    }
    if (str[i - 1] != '1')
        return (-1);
    return (1);
}

int	ft_wall_error(t_map *map)
{
	int	i;

	i = 0;
    printf("ONE\n");
    if (ft_check_border(map->map_tab[i]) == -1)
        return (0);
	i++;
    printf("TWO\n");
	while (map->map_tab[i])
	{
        if (ft_check_line(map->map_tab[i]) == -1)
            return (0);
        i++;
	}
    printf("THREE\n");
    if (ft_check_border(map->map_tab[i - 1]) == -1)
        return (0);
	return (1);
}
*/

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

void    assign_player_pos(t_map *map, char direction, int i, int j)
{
    map->p_pos_y = i;
    map->p_pos_x = j;
    map->p_direction = direction;
}

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
        return ; // comme ca si pas de data sur largeur/hauteur = plus de 1 perso sur la map donc invalide
    map->width_map = tmp;
    map->height_map = i;
}

void    parse_error(t_map *map, char *message)
{
    write(2, message, ft_strlen(message));
    if (map->map_tab)
        free_map_tab(map);
    if (map->map_data)
        free_map_data(map);
    exit (EXIT_FAILURE);
}

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
        printf("%s", map->map_tab[i]);
        i++;
    }
    printf("\nwidth map %d, height map %d, player pos x %d, player pos y %d, player direction %c\n",
    map->width_map, map->height_map, map->p_pos_x, map->p_pos_y, map->p_direction);
}

void	ft_read_map(int fd, t_map *map)
{
	char	*line;
	char	*map_line;

	line = NULL;
	map_line = NULL;
	while (42)
	{
		line = get_next_line(fd);
        // ajouter check erreur si slash dans la line
		if (!line)
            break ;
		map_line = ft_strjoin_cub3d(map_line, line);
		free(line);
	}
	map->map_tab = ft_split(map_line, '/');
    free(map_line);
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
