#ifndef SO_LONG_H
# define SO_LONG_H

// confirmar se todos estes são necessários
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <ctype.h>

#define ERR_INVALID_FILE_EXT -1
#define ERR_INVALID_CHAR -2
#define ERR_INVALID_MAP_PROPORTIONS -3
#define ERR_MISSING_WALLS -4
#define ERR_MULTIPLE_EXITS -5
#define ERR_MULTIPLE_STARTS -6
#define ERR_MAP_NOT_WIN -7

// errors.c
void	handle_error_status(int status);

// validations.c
int	file_ext_is_valid(char *file_name);
int	map_content_is_valid(char *file_name);
int	is_map_valid(char *file_name);

#endif