/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:04:30 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 18:01:48 by gjose-fr         ###   ########.fr       */
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

void	init_sprites_struct(t_sprites *sprites)
{
	sprites->floor = NULL;
	sprites->wall = NULL;
	sprites->exit = NULL;
	sprites->col = NULL;
	sprites->p_up = NULL;
	sprites->p_right = NULL;
	sprites->p_down = NULL;
	sprites->p_left = NULL;
}

void	init_maps(t_map *map)
{
	map->matrix = NULL;
	map->flood = NULL;
	init_player_coords(&(map->player));
	map->height = 0;
	map->width = 0;
}

void	init_mlx_struct(t_data *mlx)
{
	mlx->init = NULL;
	mlx->window = NULL;
}

void	init_structs(t_game *game)
{
	init_maps(&(game->map));
	init_mlx_struct(&(game->mlx));
	init_sprites_struct(&(game->mlx.sprites));
}
