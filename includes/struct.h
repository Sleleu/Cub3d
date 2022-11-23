/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:51:45 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/23 19:53:41 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct  s_map
{
    void    *mlx;
    void    *mlx_win;

    char *north;
    char *south;
    char *east;
    char *west;

    char **map_tab;

    int rgb_floor[3];
    int rgb_sky[3];

}   t_map;

#endif