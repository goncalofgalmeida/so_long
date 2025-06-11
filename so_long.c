/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:28 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/11 14:05:15 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	hooks_and_loop(t_game *game)
{
	void		*window;

	window = game->mlx.window;
	mlx_hook(window, EVENT_KEY_PRESS, MASK_KEY_PRESS, handle_keypress, game);
	mlx_hook(window, EVENT_CLOSE_WINDOW, MASK_CLOSE_WINDOW, handle_close_game, game);
	mlx_loop(game->mlx.init);
}

int		main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_game(NULL, ERR_ARGC, "Usage: ./so_long path/to/map.ber");
	if (!file_ext_is_valid(argv[1]))
		exit_game(NULL, ERR_INVALID_EXT, "Invalid file extension.");
	init_structs(&game);
	game.mlx.init = mlx_init();
	if (!game.mlx.init)
		exit_game(NULL, ERR_INIT_MLX, "Unable to initiate MLX.");
	start_game(&game, argv[1]);
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
