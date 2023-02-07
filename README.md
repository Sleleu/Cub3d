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

## Parsing methodology

According to the constraints imposed by the subject, the parsing was carried out in the following way :

![parsing_check](https://user-images.githubusercontent.com/93100775/217233450-89ad0f51-8bbe-48e6-8e9e-41b7f6090c3f.png)

- **Take data** : first pass on the .cub file, for example with a _static variable_, to get the 6 first required data. RGB colors and paths of the images can be placed in an array, and check the validity of each path and colors. In this implementation, the order of declaration of textures or colors does not matter, but must be declared correctly and without gaps or duplication.

- **Turn map into rectangle** : Once the data is retrieved, check the _longest line_ of the map, and enlarge the size of each shorter line with spaces to form a rectangular. This will facilitate the vertical check of the map.

- **Horizontal check** : check for each line if the characters are valid characters `"01NSEW "`. In case of space, check if the character preceding the space is a `1`, and if the next character following the **space string** is a `1` or the end of line. So it is possible to have space holes in a map provided that this hole is surrounded by walls.

- **Vertical check** : The vertical check follows the same logic, constant verification that a wall is present before and after a space string. The combination of the vertical and horizontal check will allow to create any type of map, rounded or with islands, while checking that there is no opening, in example a `0` not surrounded by `1`.

## Graphical rendering

### 3D perspective with raycasting

The simulation of the 3D perspective of the raycasting is operated by size of the central pixel columns, more or less long depending on the distance between the player and the wall. This distance is measured by rays crossing the 2D map, and checking if a wall is encountered. These measurements use a **digital differential analysis algorithm** to check only the useful areas, in this case the intersections between the cells of the map. This measurement is performed **as many times as there are x-pixels** on the user's screen, allowing a resource saving without having to calculate the entire screen. Here is an example of the rendering of this project _(commit ee1de0ef385d78e352bfb22914ec44ae6142da0f)_ in its state before the addition of textures :

![Screenshot from 2023-01-30 16-12-01](https://user-images.githubusercontent.com/93100775/215516735-f8ce45e1-cb8a-48fb-bb8f-835a197ff825.png)


### Final rendering

Here is an example of the final graphic rendering of the project, using the textures of the original doom game, as well as a minimap and a RGB color set :

![Screenshot from 2023-01-30 16-00-04](https://user-images.githubusercontent.com/93100775/215512948-b1079c1e-c73d-4fb2-80c4-3c19b7d2153d.png)


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

## Usage

When launching the program, it is necessary to use as argument a map located in the /maps folder

```shell
./cub3D maps/map1.cub 
```

### controls

- `WASD` to move
- `->`, `<-` or move the mouse on either side of the screen to execute a rotation
- `ESC` to quit the program


## usefull links

- https://lodev.org/cgtutor/raycasting.html
- https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
- https://guy-grave.developpez.com/tutoriels/jeux/doom-wolfenstein-raycasting/
- https://github.com/vinibiavatti1/RayCastingTutorial/wiki
- https://github.com/qst0/ft_libgfx
