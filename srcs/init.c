/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:04:30 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/11 17:02:03 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_player *player)
{
	player->x_coord = 0;
	player->y_coord = 0;
}

void	init_map(t_map *map)
{
	map->matrix = NULL;
	map->player = malloc(sizeof(t_player));
	init_player(map->player);
	map->height = 0;
	map->width = 0;
}

void	init_game(t_game *game)
{
	game->map = NULL;
}
