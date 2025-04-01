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

typedef struct s_game
{
	char	*map;
} t_game;

typedef struct s_map
{
	char	**matrix;
	int		height;
	int		width;
} t_map;

#define ERR_ARGC 2
#define ERR_INVALID_FILE_EXT 3
#define ERR_INVALID_CHAR 4
#define ERR_INVALID_MAP_PROPORTIONS 5
#define ERR_MISSING_WALLS 6
#define ERR_MULTIPLE_EXITS 7
#define ERR_MULTIPLE_STARTS 8
#define ERR_MAP_NOT_WIN 9

// errors.c
void	handle_error_status(int status);

// validations.c
int	file_ext_is_valid(char *file_name);
int	map_content_is_valid(char *file_name);
int	is_map_valid(char *file_name);

// game.c
void	create_map(t_map *map);
void	populate_map(t_map *map_ptr);
void 	start_game(t_map *map);

#endif