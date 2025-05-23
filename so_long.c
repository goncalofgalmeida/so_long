/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:28 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/23 10:26:28 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC));
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_EXT));
	game.mlx.init = mlx_init();
	if (!game.mlx.init)
		return (1);
	game.mlx.window = mlx_new_window(game.mlx.init, 800, 600, "so_long");
	init_map(&game.map);
	start_game(&game.map, argv[1]);
	mlx_loop(game.mlx.init);
	return (0);
}
