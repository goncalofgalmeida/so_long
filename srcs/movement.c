/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:45:15 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/30 13:42:57 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move_count(t_game game)
{
	ft_putstr_fd("Current move count: ", 1);
	ft_putnbr_fd(game.map.player.move_count, 1);
	ft_putchar_fd('\n', 1);
}

int	move_right(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord][player->x_coord + 1] == '1')
		return (0);
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->x_coord += 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
	return (1);
}

int	move_down(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord + 1][player->x_coord] == '1')
		return (0);
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->y_coord += 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
	return (1);
}

int	move_left(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord][player->x_coord - 1] == '1')
		return (0);
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->x_coord -= 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
	return (1);
}

int	move_up(t_map *map)
{
	t_player	*player;

	player = &map->player;
	if (map->matrix[player->y_coord - 1][player->x_coord] == '1')
		return (0);
	map->matrix[player->y_coord][player->x_coord] = '0';
	player->y_coord -= 1;
	map->matrix[player->y_coord][player->x_coord] = 'P';
	return (1);
}
