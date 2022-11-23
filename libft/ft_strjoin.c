/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:52:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/23 20:38:08 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_strssize(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (i + j);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = ft_strssize(s1, s2);
	tab = malloc(sizeof(char) * size + 1);
	tab[size] = '\0';
	if (tab == NULL)
		return (NULL);
	while (*s1)
	{
		tab[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	return (tab);
}
