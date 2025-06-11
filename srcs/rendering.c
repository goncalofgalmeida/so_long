/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:07:10 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/11 12:26:44 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_game *game)
{
	t_sprites	*sprites;
	t_data		*mlx;
	int			h;
	int			w;

	sprites = &(game->mlx.sprites);
	mlx = &(game->mlx);
	sprites->floor = mlx_xpm_file_to_image(mlx->init, BG_PATH, &w, &h);
	sprites->wall = mlx_xpm_file_to_image(mlx->init, WALL_PATH, &w, &h);
	sprites->exit = mlx_xpm_file_to_image(mlx->init, EXIT_PATH, &w, &h);
	sprites->col = mlx_xpm_file_to_image(mlx->init, COL_PATH, &w, &h);
	sprites->p_up = mlx_xpm_file_to_image(mlx->init, P_UP_PATH, &w, &h);
	sprites->p_right = mlx_xpm_file_to_image(mlx->init, P_RIGHT_PATH, &w, &h);
	sprites->p_down = mlx_xpm_file_to_image(mlx->init, P_DOWN_PATH, &w, &h);
	sprites->p_left = mlx_xpm_file_to_image(mlx->init, P_LEFT_PATH, &w, &h);
	if (!sprites->floor || !sprites->wall || !sprites->exit
		|| !sprites->col || !sprites->p_up || !sprites->p_right
		|| !sprites->p_down || !sprites->p_left)
	{
		exit_game(game, ERR_LOADING_IMGS, "Unable to load all images.");
	}
}

void	render_correct_p_sprite(t_game *game, void *window, int x, int y)
{
	t_data		*mlx;
	t_sprites	sprites;
	int			player_dir;

	mlx = &game->mlx;
	player_dir = game->map.player.direction;
	sprites = mlx->sprites;
	if (player_dir == DIR_UP)
		mlx_put_image_to_window(mlx->init, window, sprites.p_up, x, y);
	if (player_dir == DIR_RIGHT)
		mlx_put_image_to_window(mlx->init, window, sprites.p_right, x, y);
	if (player_dir == DIR_DOWN)
		mlx_put_image_to_window(mlx->init, window, sprites.p_down, x, y);
	if (player_dir == DIR_LEFT)
		mlx_put_image_to_window(mlx->init, window, sprites.p_left, x, y);
}

void	render_sprite(t_game *game, char cell_value, int x, int y)
{
	t_data		*mlx;
	void		*window;
	t_sprites	sprites;
	int			new_x;
	int			new_y;

	mlx = &game->mlx;
	window = mlx->window;
	sprites = mlx->sprites;
	new_x = x * TILE_SIZE;
	new_y = y * TILE_SIZE;
	if (cell_value == '1')
		mlx_put_image_to_window(mlx->init, window, sprites.wall, new_x, new_y);
	else if (cell_value == '0')
		mlx_put_image_to_window(mlx->init, window, sprites.floor, new_x, new_y);
	else if (cell_value == 'P')
		render_correct_p_sprite(game, window, new_x, new_y);
	else if (cell_value == 'C')
		mlx_put_image_to_window(mlx->init, window, sprites.col, new_x, new_y);
	else if (cell_value == 'E')
		mlx_put_image_to_window(mlx->init, window, sprites.exit, new_x, new_y);
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
