/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:04:30 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/06 23:14:51 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player_coords(t_player *player)
{
	player->x_coord = 0;
	player->y_coord = 0;
	player->direction = DIR_RIGHT;
	player->move_count = 0;
}

void	init_maps(t_map *map)
{
	map->matrix = NULL;
	map->flood = NULL;
	init_player_coords(&(map->player));
	map->height = 0;
	map->width = 0;
}
