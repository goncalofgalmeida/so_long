/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:27:10 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 17:36:12 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// allow movement for upper keys (if CAPS is on) and for arrows
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
		// TODO make check_win() function?
	}
	return (0);
}

int	handle_close_game(t_game *game)
{
	exit_game(game, 0, NULL); // qual devia ser o status aqui?
	return (0);
}
