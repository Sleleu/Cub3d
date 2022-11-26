/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:51:45 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/26 20:40:51 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct  s_map
{
    // display pointer
    void    *mlx;
    void    *mlx_win;

    // path of textures
    char    *north;
    char    *south;
    char    *east;
    char    *west;

    // map data
    char    **map_tab;
    char    **map_data;
    int     width_map;
    int     height_map;

    // player data
    int     p_pos_x;
    int     p_pos_y;
    char    p_direction;

    // color data
    int     rgb_floor[3];
    int     rgb_sky[3];

    // image pointer
    void    *north_wall;
    void    *south_wall;
    void    *east_wall;
    void    *west_wall;

    // parsing variables
    char    *line;
    char    *map_line;

	// images
	void	*img_no;
	void	*img_so;
	void	*img_ea;
	void	*img_we;

}   t_map;

#endif