#include "../so_long.h"

void	handle_error_status(int status)
{
	printf("Error\n");
	if (status == ERR_INVALID_FILE_EXT)
		printf("Invalid file extension.\n");
	else if (status == ERR_INVALID_CHAR)
		printf("Invalid character found.\n");
	else if (status == ERR_INVALID_MAP_PROPORTIONS)
		printf("Map is not a rectangle.\n");
	else if (status == ERR_MISSING_WALLS)
		printf("Map is not surrounded by walls.\n");
	else if (status == ERR_MULTIPLE_EXITS)
		printf("Map has multiple exits.\n");
	else if (status == ERR_MULTIPLE_STARTS)
		printf("Map has multiple starts.\n");
	else if (status == ERR_MAP_NOT_WIN)
		printf("Map is not winnable.\n");
	else
		printf("Undefined error, must look into it.\n");
}
