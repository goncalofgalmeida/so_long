/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:28 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/03 17:49:56 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	hooks_and_loop(t_game *game)
{
	void		*window;

	window = game->mlx.window;
	mlx_hook(window, EVENT_KEY_PRESS, MASK_KEY_PRESS, handle_keypress, game); // check if last NULL
	mlx_hook(window, EVENT_CLOSE_WINDOW, MASK_CLOSE_WINDOW, handle_close_game, game); // check if last NULL
	mlx_loop(game->mlx.init);
}

int		main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC));
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_EXT));
	game.mlx.init = mlx_init();
	if (!game.mlx.init)
		return (1);
	init_maps(&game.map);
	start_game(&game.map, argv[1]);
	game.mlx.window = mlx_new_window(game.mlx.init,
		game.map.width * TILE_SIZE,
		game.map.height * TILE_SIZE,
		"so_long");
	if (!game.mlx.window)
		return (1);
	load_images(&game);
	render_map(&game);
	hooks_and_loop(&game);
	return (0);
}
