/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:04:30 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/23 10:47:49 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player_coords(t_player *player)
{
	player->x_coord = 0;
	player->y_coord = 0;
	player->move_count = 0;
}

void	init_map(t_map *map)
{
	map->matrix = NULL;
	init_player_coords(&(map->player));
	map->height = 0;
	map->width = 0;
}
