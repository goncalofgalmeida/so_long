/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:41:47 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/02 17:32:27 by gjose-fr         ###   ########.fr       */
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

# define ERR_ARGC 2
# define ERR_INVALID_EXT 3
# define ERR_INVALID_CHAR 4
# define ERR_INVALID_MAP_PROPORTIONS 5
# define ERR_MISSING_WALLS 6
# define ERR_MULTIPLE_EXITS 7
# define ERR_MULTIPLE_STARTS 8
# define ERR_MAP_NOT_WIN 9

typedef struct s_game
{
	char	*map;
}	t_game;

typedef struct s_player
{
	int		x_coord;
	int		y_coord;
}	t_player;

typedef struct s_map
{
	char		**matrix;
	int			height;
	int			width;
	t_player	*p_coords;
}	t_map;

// errors.c
void	handle_error_status(int status);

// validations.c
int		file_ext_is_valid(char *file_name);
int		map_content_is_valid(char *file_name);
int		is_map_valid(char *file_name);

// parsing_utils.c
int	get_map_height(char *file_content);
int	get_map_width(char *file_content);

// game.c
void	get_and_set_map(t_map *map_ptr, char *file_path);
void	start_game(t_map *map, char *file_path);

// init.c
void	init_map(t_map *map);

// player.c
void	move_right(t_map *map);

#endif