/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:15:09 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 00:10:02 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_char(char c, char *valid_char)
{
	int	i;

	i = 0;
	while (valid_char[i])
	{
		if (c == valid_char[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_cub3d(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_resize_line(char *str, int size)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * size + 1);
	if (!new_str)
		return (NULL);
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (i < size)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[size] = '\0';
	if (str)
		free(str);
	return (new_str);
}

/*
	FT_STRJOIN_CUB3D
	
	A simple strjoin but this one add a '/' separator at the
	end of the string, and don't count the '\n' for the size.
*/

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
