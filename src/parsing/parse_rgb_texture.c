/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:15:36 by sleleu            #+#    #+#             */
/*   Updated: 2022/12/30 15:21:38 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	GET_TEXTURE_PATH

	Check the number of lines, and stock the path of the texture image in
	the structure with ft_strjoin_cub3d(), to remove the potential '\n' 
	at the end of the line.
*/

void	get_texture_path(t_map *map, char **path, char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
		i++;
	if (i == 3 && split_line[2][0] == '\n')
		free(split_line[i--]);
	if (i != 2 || *path)
	{
		free_double_array(split_line);
		parse_error(map, "Error\nTexture line is incorrect\n");
	}
	*path = ft_strjoin(*path, split_line[1]);
	if (path[0][ft_strlen_cub3d(*path)] == '\n')
		path[0][ft_strlen_cub3d(*path)] = '\0';
	free_double_array(split_line);
}

/*
	PARSE_RGB_LINE

	The rgb code is correct if there is 2 comma, only digits,
	and a line < 11.
*/

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
		if (line[i] == ',' && line[i + 1] && line[i + 1] == ',')
			return (0);
		else if ((!ft_isdigit(line[i])) && line[i] != ',')
			return (0);
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

/*
	CHECK_RGB

	Assign the rgb code in the rgb array stocked in the structure, and
	check if the value is between 0 and 255.
*/

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

/*
	GET_RGB

	This function check the number of lines split, and call check_rgb().
	If i = 3 and the 3rd line is only '\n', it means that spaces have been
	added after the rgb code.
	If check_rgb() return an error, there is an error in the rgb code.
*/

void	get_rgb(t_map *map, int *rgb, char **split_line)
{
	int	i;

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
