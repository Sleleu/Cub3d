# Cub3d

## Subject

This project provided by 42 school aims to explore the functioning of raycasting by creating a simulated "3D" environment in which the user can move freely within a map.

The project must respect certain constraints :

- Using minilibx
- Display different wall textures for north, south, east and west
- Set colors for the floor and ceiling
- The left and right arrow keys must allows to rotate the perspective
- `WASD` must allow to move the point of view
- `ESC` and the cross on the window's frame must close the program cleanly
- The program take a map only with the `.cub` extension

The map can be freely created by the user, must be closed, and composed by the following characters to be accepted :
- `0` for the ground
- `1` for a wall
- `N` `S` `E` `W` for the spwaning orientation


Here is an example of a valid map provided by the subject, with the path for textures and the RGB colors for the floor and ceiling :

```shell
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Installation

### Clone the repository

```shell
git clone git@github.com:Sleleu/Cub3d.git
cd Cub3d
```

### Install the minilibx library

In the ./Cub3d folder :

```shell
git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
make
```

## usefull links

- https://lodev.org/cgtutor/raycasting.html
- https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/
- https://github.com/vinibiavatti1/RayCastingTutorial/wiki
- https://github.com/qst0/ft_libgfx
