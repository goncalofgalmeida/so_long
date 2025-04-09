/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:45:15 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/09 11:29:31 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	move_right(t_map *map)
{
	t_player	*player;

	player = map->player;
	map->matrix[player->x_coord][player->y_coord] = '0';
	player->y_coord += 1;
	map->matrix[player->x_coord][player->y_coord] = 'P';
}

void	move_down(t_map *map)
{
	t_player	*player;

	player = map->player;
	map->matrix[player->x_coord][player->y_coord] = '0';
	player->x_coord += 1;
	map->matrix[player->x_coord][player->y_coord] = 'P';
}

void	move_left(t_map *map)
{
	t_player	*player;

	player = map->player;
	map->matrix[player->x_coord][player->y_coord] = '0';
	player->y_coord -= 1;
	map->matrix[player->x_coord][player->y_coord] = 'P';
}

void	move_up(t_map *map)
{
	t_player	*player;

	player = map->player;
	map->matrix[player->x_coord][player->y_coord] = '0';
	player->x_coord -= 1;
	map->matrix[player->x_coord][player->y_coord] = 'P';
}
