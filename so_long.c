/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:28 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/02 16:10:03 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		status;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC), ERR_ARGC);
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_EXT), ERR_INVALID_EXT);
	status = is_map_valid(argv[1]); // chamar aqui a funcao file_ext_is_valid(argv[1])
	if (status != 1)
		return (handle_error_status(status), status); // dar free ao mapa que já foi alocado?
	init_map(&map);
	start_game(&map, argv[1]);
	return (0);
}
