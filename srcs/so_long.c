#include "../so_long.h"

int	main(int argc, char **argv)
{
	/* t_game	game; */
	t_map	map;
	int		status;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC), ERR_ARGC);
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_FILE_EXT), ERR_INVALID_FILE_EXT);
	status = is_map_valid(argv[1]); // chamar aqui a funcao file_ext_is_valid(argv[1])
	if (status != 1)
		return (handle_error_status(status), status); // dar free ao mapa que já foi alocado?
	map.matrix = NULL;
	map.height = 5;
	map.width = 8;
	start_game(map);
	return (0);
}
