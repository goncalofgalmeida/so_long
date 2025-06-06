/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:07:10 by g24force          #+#    #+#             */
/*   Updated: 2025/06/06 23:09:59 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	t_sprites	*sprites;
	int			height;
	int			width;
	
	sprites = &(game->mlx.sprites);
	sprites->floor = mlx_xpm_file_to_image(game->mlx.init, BG_PATH, &width, &height);
	sprites->wall = mlx_xpm_file_to_image(game->mlx.init, WALL_PATH, &width, &height);
	sprites->exit = mlx_xpm_file_to_image(game->mlx.init, EXIT_PATH, &width, &height);
	sprites->collectible = mlx_xpm_file_to_image(game->mlx.init, COL_PATH, &width, &height);
	sprites->p_up = mlx_xpm_file_to_image(game->mlx.init, P_UP_PATH, &width, &height);
	sprites->p_right = mlx_xpm_file_to_image(game->mlx.init, P_RIGHT_PATH, &width, &height);
	sprites->p_down = mlx_xpm_file_to_image(game->mlx.init, P_DOWN_PATH, &width, &height);
	sprites->p_left = mlx_xpm_file_to_image(game->mlx.init, P_LEFT_PATH, &width, &height);
	if (!sprites->floor || !sprites->wall || !sprites->exit || !sprites->collectible || !sprites->p_up) //check other dirs
	{
		handle_error_status(193); // ERR_LOADING_IMG
	}
}

void	render_sprite(t_game *game, char cell_value, int x, int y)
{
	t_data		*mlx;
	void		*window;
	t_sprites	sprites;

	mlx = &game->mlx;
	window = mlx->window;
	sprites = mlx->sprites;
	if (cell_value == '1')
		mlx_put_image_to_window(mlx->init, window, sprites.wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (cell_value == '0')
		mlx_put_image_to_window(mlx->init, window, sprites.floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (cell_value == 'P')
	{
		if (game->map.player.direction == DIR_UP)
			mlx_put_image_to_window(mlx->init, window, sprites.p_up, x * TILE_SIZE, y * TILE_SIZE);
		if (game->map.player.direction == DIR_RIGHT)
			mlx_put_image_to_window(mlx->init, window, sprites.p_right, x * TILE_SIZE, y * TILE_SIZE);
		if (game->map.player.direction == DIR_DOWN)
			mlx_put_image_to_window(mlx->init, window, sprites.p_down, x * TILE_SIZE, y * TILE_SIZE);
		if (game->map.player.direction == DIR_LEFT)
			mlx_put_image_to_window(mlx->init, window, sprites.p_left, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (cell_value == 'C')
		mlx_put_image_to_window(mlx->init, window, sprites.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (cell_value == 'E')
		mlx_put_image_to_window(mlx->init, window, sprites.exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_sprite(game, game->map.matrix[y][x], x, y);
			x++;
		}
		y++;
	}
}
