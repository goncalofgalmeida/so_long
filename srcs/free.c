/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:32:19 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 17:51:26 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all_imgs(t_game *game)
{
	t_sprites	*sprites;

	sprites = &(game->mlx.sprites);
	mlx_destroy_image(game->mlx.init, sprites->floor);
	mlx_destroy_image(game->mlx.init, sprites->wall);
	mlx_destroy_image(game->mlx.init, sprites->exit);
	mlx_destroy_image(game->mlx.init, sprites->col);
	mlx_destroy_image(game->mlx.init, sprites->p_up);
	mlx_destroy_image(game->mlx.init, sprites->p_right);
	mlx_destroy_image(game->mlx.init, sprites->p_down);
	mlx_destroy_image(game->mlx.init, sprites->p_left);
}

void	free_matrixes(t_map *map)
{
	int	i;

	i = 0;
	if (map->matrix)
	{
		while (i < map->height)
		{
			free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	i = 0;
	if (map->flood)
	{
		while (i < map->height)
		{
			free(map->flood[i]);
			i++;
		}
		free(map->flood);
	}
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map.matrix && game->map.flood)
		free_matrixes(&(game->map));
	if (game->mlx.sprites.floor)
		free_all_imgs(game);
	if (game->mlx.window)
		mlx_destroy_window(game->mlx.init, game->mlx.window);
	mlx_destroy_display(game->mlx.init);
	free(game->mlx.init);
}
