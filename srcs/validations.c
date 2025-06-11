/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:38:25 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/11 12:26:18 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(t_map *map)
{
	int	first_line_width;
	int	current_line_width;
	int	i;

	first_line_width = map->width;
	i = 1;
	while (map->matrix[i])
	{
		current_line_width = ft_strlen(map->matrix[i]);
		if (current_line_width != first_line_width)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	int		y;
	int		x;

	x = 0;
	while (map->matrix[0][x])
	{
		if (map->matrix[0][x] != '1' || map->matrix[map->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->matrix[y][0] != '1' || map->matrix[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	map_content_is_valid(char *file_content)
{
	char	*valid_chars;
	int		len;

	len = ft_strlen(file_content);
	if (len >= 1 && (file_content[0] == '\n' || file_content[len - 1] == '\n'))
		return (0);
	valid_chars = "10PCE\n";
	while (*file_content)
	{
		if (!ft_strchr(valid_chars, *file_content))
			return (0);
		file_content++;
	}
	return (1);
}

void	check_chars_count(t_game *game)
{
	t_map	*map;

	map = &(game->map);
	if (map->player_count != 1)
		exit_game(game, ERR_MULTIPLE_STARTS, "Map has multiple starts.");
	if (map->exit_count != 1)
		exit_game(game, ERR_MULTIPLE_EXITS, "The number of exits is not one.");
	if (map->collectibles_count <= 0)
		exit_game(game, ERR_NO_COLLECTIBLES, "No collectibles found.");
}

void	parse_map(t_game *game)
{
	t_map	*map;

	map = &(game->map);
	if (!is_rectangular(map))
		exit_game(game, ERR_INVALID_MAP_PROPORTIONS, "Map is not a rectangle.");
	if (!is_surrounded_by_walls(map))
		exit_game(game, ERR_MISSING_WALL, "Map is not surrounded by walls.");
	check_chars_count(game);
	flood_fill(map->flood, map->player.y_coord, map->player.x_coord);
	if (!is_winnable(map->flood))
		exit_game(game, ERR_MAP_NOT_WIN, "Map is not winnable.");
}
