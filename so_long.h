/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:41:47 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/11 14:02:17 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <ctype.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef enum e_error_codes
{
	ERR_ARGC = 2,
	ERR_INVALID_EXT,
	ERR_INIT_MLX,
	ERR_OPENING_FILE,
	ERR_INV_CHARS,
	ERR_INVALID_MAP_PROPORTIONS,
	ERR_MISSING_WALL,
	ERR_MULTIPLE_EXITS,
	ERR_MULTIPLE_STARTS,
	ERR_NO_COLLECTIBLES,
	ERR_MAP_NOT_WIN,
	ERR_LOADING_IMGS,
}	t_error_codes;

typedef enum e_player_dir
{
	DIR_UP = 100,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
}	t_player_dir;

// mlx related
# define TILE_SIZE 64

// mlx sprites paths
# define BG_PATH "textures/environment/bg.xpm"
# define WALL_PATH "textures/environment/asteroid-01.xpm"
# define EXIT_PATH "textures/environment/portal.xpm"
# define COL_PATH "textures/collectibles/collectible.xpm"
# define P_UP_PATH "textures/characters/p-red-up.xpm"
# define P_RIGHT_PATH "textures/characters/p-red-right.xpm"
# define P_DOWN_PATH "textures/characters/p-red-down.xpm"
# define P_LEFT_PATH "textures/characters/p-red-left.xpm"

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
	void	*floor;
	void	*wall;
	void	*exit;
	void	*col;
	void	*p_up;
	void	*p_right;
	void	*p_down;
	void	*p_left;
}	t_sprites;

typedef struct s_player
{
	int	x_coord;
	int	y_coord;
	int	direction;
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
void	exit_game(t_game *game, int status, char *msg);

// flood.c
void	flood_fill(char **flood, int y, int x);
int		is_winnable(char **flood);

//free.c
void	free_all(t_game *game);

// game.c
char	*get_file_content(char *file_path);
void	get_and_set_map(t_game *game, char *file_path);
void	start_game(t_game *game, char *file_path);

// handling.c
int		handle_keypress(int keycode, t_game *game);
int		handle_close_game(t_game *game);

// init.c
void	init_maps(t_map *map);
void	init_structs(t_game *game);

// movement.c
void	print_move_count(t_game game);
int		move_right(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_up(t_game *game);

// parsing_utils.c
int		get_map_height(char *file_content);
int		get_map_width(char *file_content);
void	get_and_set_player_coords(t_map *map);
void	get_and_set_chars_count(t_map *map, char *file_content);
int		is_rectangular(t_map *map);
int		is_surrounded_by_walls(t_map *map);

// rendering.c
void	load_images(t_game *game);
void	render_map(t_game *game);

// validations.c
int		file_ext_is_valid(char *file_name);
int		map_content_is_valid(char *file_content);
void	parse_map(t_game *game);

#endif