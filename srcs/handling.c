/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:27:10 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/11 12:42:17 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	int	moved;

	moved = 0;
	if (keycode == KEY_W)
		moved = move_up(game);
	else if (keycode == KEY_D)
		moved = move_right(game);
	else if (keycode == KEY_S)
		moved = move_down(game);
	else if (keycode == KEY_A)
		moved = move_left(game);
	else if (keycode == KEY_ESC)
		moved = handle_close_game(game);
	if (moved)
	{
		game->map.player.move_count++;
		print_move_count(*game);
		render_map(game);
	}
	return (0);
}

int	handle_close_game(t_game *game)
{
	exit_game(game, 0, NULL);
	return (0);
}
