/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:15:36 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 19:40:21 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture_path(t_map *map, char **path, char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
		i++;
	if (i == 3 && split_line[2][0] == '\n')
		free(split_line[i--]);
	if (i != 2)
	{
		free_double_array(split_line);
		parse_error(map, "Error\nTexture line is incorrect\n");
	}
	*path = ft_strjoin_cub3d(*path, split_line[1]);
	free_double_array(split_line);
}

int	parse_rgb_line(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	if (!ft_isdigit(line[0]) || !ft_isdigit(line[ft_strlen_cub3d(line) - 1])
		|| ft_strlen_cub3d(line) > 11)
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

int	check_rgb(int *rgb, char *line)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (!parse_rgb_line(line))
		return (0);
	while (line[i])
	{
		if (i == 0)
			rgb[0] = ft_atoi(line);
		else if (line[i] == ',')
			rgb[j++] = ft_atoi(line + i + 1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
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
	if ((i != 2) || !check_rgb(rgb, split_line[1]))
	{
		free_double_array(split_line);
		parse_error(map, "Error\nRGB line is incorrect\n");
	}
	free_double_array(split_line);
}
