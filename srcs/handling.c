/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:27:10 by g24force          #+#    #+#             */
/*   Updated: 2025/06/06 22:42:49 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// allow movement for upper keys (if CAPS is on) and for arrows
int		handle_keypress(int keycode, t_game *game)
{
	int	moved;

	moved = 0;
	if (keycode == KEY_W)
		moved = move_up(&game->map);
	else if (keycode == KEY_D)
		moved = move_right(&game->map);
	else if (keycode == KEY_S)
		moved = move_down(&game->map);
	else if (keycode == KEY_A)
		moved = move_left(&game->map);
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

int		handle_close_game(t_game *game)
{
	// free stuff
	(void)game; // delete line
	exit(0);
	return (0);
}
