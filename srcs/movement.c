/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:45:15 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/30 01:25:36 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

int		handle_keypress(int keycode, t_game *game) // mover para novo handle_keys.c ?
{
	if (keycode == KEY_W)
		move_up(&game->map);
	else if (keycode == KEY_D)
		move_right(&game->map);
	else if (keycode == KEY_S)
		move_down(&game->map);
	else if (keycode == KEY_A)
		move_left(&game->map);
	else if (keycode == KEY_ESC)
		handle_close_game(game);
	render_map(game);
	return (0);
}

void	move_right(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord][player->x_coord + 1] == '1')
		return;
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->x_coord += 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
}

void	move_down(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord + 1][player->x_coord] == '1')
		return;
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->y_coord += 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
}

void	move_left(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord][player->x_coord - 1] == '1')
		return;
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->x_coord -= 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
}

void	move_up(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord - 1][player->x_coord] == '1')
		return;
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->y_coord -= 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
}
