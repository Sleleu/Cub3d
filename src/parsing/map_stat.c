/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:48:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/25 22:17:07 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	ASSIGN_PLAYER_POS
	
	When a char E/N/S/W is found during the parsing,
	the position and direction of the player is stocked in the structure.
*/

void    assign_player_pos(t_map *map, char direction, int i, int j)
{
    map->p_pos_y = i;
    map->p_pos_x = j;
    map->p_direction = direction;
}

/*
    SET_SIZE_DATA
    
    2 loops to get the height and width of the map, based on
    the longer line in the array.
    The player position and direction is found during the
    loop, and if there is more than one player, set_size_data
    don't set the height and width of the map.
*/

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
        return ;
    map->width_map = tmp;
    map->height_map = i;
}

// void	get_map_stat(t_map *map)
// {
	
// }