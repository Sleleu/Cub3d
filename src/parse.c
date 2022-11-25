/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:13:33 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 15:41:44 by sleleu           ###   ########.fr       */
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

int	ft_strlen_cub3d(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_cub3d(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen_cub3d(s1) + ft_strlen_cub3d(s2));
	tab = malloc(sizeof(char) * size + 2);
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[size] = '/';
	tab[size + 1] = '\0';
	if (s1)
		free(s1);
	return (tab);
}

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
        printf("%s", line);
		if (!line)
			break ;
		map_line = ft_strjoin_cub3d(map_line, line);
		free(line);
	}
	map->map_tab = ft_split(map_line, '/');
	free(map_line);
}

int ft_parse_map(t_map *map, int fd)
{
    ft_read_map(fd, map);
    if (error_map(map))
        return (0);
    close(fd);

    return (1);
}