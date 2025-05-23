/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:41:47 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/23 09:54:15 by g24force         ###   ########.fr       */
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
# define ERR_MISSING_WALLS 7
# define ERR_MULTIPLE_EXITS 8
# define ERR_MULTIPLE_STARTS 9
# define ERR_MAP_NOT_WIN 10
# define ERR_NO_COLLECTIBLES 11

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
	void	*init;
	void	*window;
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
int		check_map(char *file_name);

// parsing_utils.c
int		get_map_height(char *file_content);
int		get_map_width(char *file_content);
void	get_and_set_player_coords(t_map *map);

// game.c
char	*get_file_content(char *file_path);
void	get_and_set_map(t_map *map_ptr, char *file_path);
void	start_game(t_map *map, char *file_path);

// init.c
void	init_map(t_map *map);

// player.c
void	move_right(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_up(t_map *map);

#endif