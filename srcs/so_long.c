#include "../libft/libft.h"
#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		status;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC), ERR_ARGC);
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_FILE_EXT), ERR_INVALID_FILE_EXT);
	status = is_map_valid(argv[1]);
	if (status != 1)
		return (handle_error_status(status), status); // dar free ao mapa que já foi alocado?
	if (!init_game(&game))
		return (handle_error_status(ERR_INIT_FAIL), free_game(&game), ERR_INIT_FAIL);
	start_game(&game);
	free_game(&game);
	return (0);
}
