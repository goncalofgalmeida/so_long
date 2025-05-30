/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:41:47 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:54 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// confirmar se todos estes são necessários
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <ctype.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"


// mudar para enum
# define ERR_ARGC 2
# define ERR_INVALID_EXT 3
# define ERR_OPENING_FILE 4
# define ERR_INVALID_CHAR 5
# define ERR_INVALID_MAP_PROPORTIONS 6
# define ERR_MISSING_WALL 7
# define ERR_MULTIPLE_EXITS 8
# define ERR_MULTIPLE_STARTS 9
# define ERR_MAP_NOT_WIN 10
# define ERR_NO_COLLECTIBLES 11

// mlx related
# define TILE_SIZE 64

// mlx sprites paths
# define GRASS_PATH "textures/environment/grass-1.xpm"
# define TREE_PATH "textures/environment/tree.xpm"
# define COL1_PATH "textures/collectibles/collectible-1.xpm"
# define PLAYER_PATH "textures/characters/dog.xpm"

// mlx events and masks
# define EVENT_KEY_PRESS 2
# define MASK_KEY_PRESS (1L << 0)
# define EVENT_CLOSE_WINDOW 17
# define MASK_CLOSE_WINDOW (1L << 17)

// mlx key codes
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307

typedef struct s_sprites
{
	void	*player;
	void	*collectible;
	void	*wall;
	void	*grass;
}	t_sprites;

typedef struct s_player
{
	int	x_coord;
	int	y_coord;
	int	move_count;	
}	t_player;

typedef struct s_map
{
	char		**matrix;
	char		**flood;
	int			height;
	int			width;
	int			player_count;
	int			collectibles_count;
	int			exit_count;
	t_player	player;
}	t_map;

typedef struct s_data
{
	void		*init;
	void		*window;
	t_sprites	sprites;
}	t_data;

typedef struct s_game
{
	t_map	map;
	t_data	mlx;
}	t_game;

// errors.c
int		handle_error_status(int status);

// validations.c
int		file_ext_is_valid(char *file_name);
int		map_content_is_valid(char *file_content);
void	parse_map(t_map *map);

// parsing_utils.c
int		get_map_height(char *file_content);
int		get_map_width(char *file_content);
void	get_and_set_player_coords(t_map *map);
void	get_and_set_chars_count(t_map *map, char *file_content);
int		is_rectangular(t_map *map);
int		is_surrounded_by_walls(t_map *map);
void	print_map(t_map map); // delete

// game.c
char	*get_file_content(char *file_path);
void	get_and_set_map(t_map *map_ptr, char *file_path);
void	start_game(t_map *map, char *file_path);

// init.c
void	init_map(t_map *map);

// rendering.c
void	load_images(t_game *game);
void	render_map(t_game *game);

// movement.c
void	print_move_count(t_game game);
int	move_right(t_map *map);
int	move_down(t_map *map);
int	move_left(t_map *map);
int	move_up(t_map *map);

// handling.c
int		handle_keypress(int keycode, t_game *game);
int		handle_close_game(t_game *game);

//free.c

#endif