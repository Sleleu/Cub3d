/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:51:45 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 15:45:15 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct  s_map
{
    // display pointer
    void    *mlx;
    void    *mlx_win;

    
    char    *north;
    char    *south;
    char    *east;
    char    *west;

    // map data
    char    **map_tab;
    int     width_map;
    int     height_map;

    // player data
    int     pos_x;
    int     pos_y;
    char    orientation;

    // color data
    int     rgb_floor[3];
    int     rgb_sky[3];

    // image pointer
    void    *north_wall;
    void    *south_wall;
    void    *east_wall;
    void    *west_wall;

}   t_map;

#endif