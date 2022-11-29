/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:27:14 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/29 16:35:09 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	convert_degree_radians(int degree)
{
	double	radians;
	double	pi;

	pi = 3.14159265358979;
	radians = degree * pi / 180;
	ft_printf("pipi\n");
	return (radians);
}
