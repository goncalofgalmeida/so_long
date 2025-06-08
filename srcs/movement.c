/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:45:15 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/08 12:26:35 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move_count(t_game game)
{
	ft_putstr_fd("Current move count: ", 1);
	ft_putnbr_fd(game.map.player.move_count, 1);
	ft_putchar_fd('\n', 1);
}

int	move_right(t_game *game)
{
	char		**matrix;
	t_player	*player;

	matrix = game->map.matrix;
	player = &game->map.player;
	if (matrix[player->y_coord][player->x_coord + 1] == '1')
		return (0);
	if (matrix[player->y_coord][player->x_coord + 1] == 'C')
		game->map.collectibles_count--;
	if (matrix[player->y_coord][player->x_coord + 1] == 'E')
	{
		if (game->map.collectibles_count == 0)
		{
			game->map.player.move_count++;
			print_move_count(*game);
			game_over(game);
		}
		else
			return (0);
	}
	matrix[player->y_coord][player->x_coord] = '0';
	player->x_coord += 1;
	matrix[player->y_coord][player->x_coord] = 'P';
	player->direction = DIR_RIGHT;
	return (1);
}

int	move_down(t_game *game)
{
	char		**matrix;
	t_player	*player;

	matrix = game->map.matrix;
	player = &game->map.player;
	if (matrix[player->y_coord + 1][player->x_coord] == '1')
		return (0);
	if (matrix[player->y_coord + 1][player->x_coord] == 'C')
		game->map.collectibles_count--;
	if (matrix[player->y_coord + 1][player->x_coord] == 'E')
	{
		if (game->map.collectibles_count == 0)
		{
			game->map.player.move_count++;
			print_move_count(*game);
			game_over(game);
		}
		else
			return (0);
	}
	matrix[player->y_coord][player->x_coord] = '0';
	player->y_coord += 1;
	matrix[player->y_coord][player->x_coord] = 'P';
	player->direction = DIR_DOWN;
	return (1);
}

int	move_left(t_game *game)
{
	char		**matrix;
	t_player	*player;

	matrix = game->map.matrix;
	player = &game->map.player;
	if (matrix[player->y_coord][player->x_coord - 1] == '1')
		return (0);
	if (matrix[player->y_coord][player->x_coord - 1] == 'C')
		game->map.collectibles_count--;
	if (matrix[player->y_coord][player->x_coord - 1] == 'E')
	{
		if (game->map.collectibles_count == 0)
		{
			game->map.player.move_count++;
			print_move_count(*game);
			game_over(game);
		}
		else
			return (0);
	}
	matrix[player->y_coord][player->x_coord] = '0';
	player->x_coord -= 1;
	matrix[player->y_coord][player->x_coord] = 'P';
	player->direction = DIR_LEFT;
	return (1);
}

int	move_up(t_game *game)
{
	char		**matrix;
	t_player	*player;

	matrix = game->map.matrix;
	player = &game->map.player;
	if (matrix[player->y_coord - 1][player->x_coord] == '1')
		return (0);
	if (matrix[player->y_coord - 1][player->x_coord] == 'C')
		game->map.collectibles_count--;
	if (matrix[player->y_coord - 1][player->x_coord] == 'E')
	{
		if (game->map.collectibles_count == 0)
		{
			game->map.player.move_count++;
			print_move_count(*game);
			game_over(game);
		}
		else
			return (0);
	}
	matrix[player->y_coord][player->x_coord] = '0';
	player->y_coord -= 1;
	matrix[player->y_coord][player->x_coord] = 'P';
	player->direction = DIR_UP;
	return (1);
}
