/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:51:45 by sleleu            #+#    #+#             */
/*   Updated: 2022/11/28 20:26:54 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct  s_map
{
    // display data
    void    *mlx;
    void    *mlx_win;
	t_img	img;
	int		display_width;
	int		display_height;

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
	char   direction;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;

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

	//raycasting
	double	ray_dir_x;
	double	ray_dir_y;
	double	cam_x;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpwalldist;
	int		map_x;
	int		map_y; // coordonnees
	int		step_x;
	int		step_y;
	int		wall_side;
	int		wall_dist;
	int		size_line;
	int		start_line;
	int		end_line;
	double	speed;
	double	rot_speed;

}   t_map;

#endif