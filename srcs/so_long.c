#include "../libft/libft.h"
#include "../so_long.h"

	// fazer parsing e verificação do ficheiro
		// ficheiro tem de ser do tipo .ber FEITO!!!!!!!!!!!
		// mapa tem de ter só os 5 chars permitidos (0, 1, C, E, P)
			// Só 1 P
			// Só 1 E
			// 1+ C
		// mapa tem de ser ganhavel
	// convertê-lo numa matriz

int	main(int argc, char **argv)
{
	int	status;
	if (argc == 2)
	{
		if (!file_ext_is_valid(argv[1]))
		{
			handle_error_status(ERR_INVALID_FILE_EXT);
			return (ERR_INVALID_FILE_EXT);
		}
		status = is_map_valid(argv[1]);
		if (status != 1)
		{
			handle_error_status(status);
			// dar free ao mapa que já foi alocado
			return (status);
		}
	}
	return (0);
}