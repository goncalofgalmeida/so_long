/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:27:49 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/23 10:05:15 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Counts number of \n and adds 1 to count the last line
int	get_map_height(char *file_content)
{
	int	height;

	height = 0;
	while (*file_content)
	{
		if (*file_content == '\n')
			height++;
		file_content++;
	}
	height++;
	return (height);
}

int	get_map_width(char *file_content)
{
	int	width;

	width = 0;
	while (file_content[width] && file_content[width] != '\n')
		width++;
	return (width);
}

void	get_and_set_player_coords(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->matrix[x])
	{
		y = 0;
		while (map->matrix[x][y])
		{
			if (map->matrix[x][y] == 'P')
			{
				map->player.x_coord = x;
				map->player.y_coord = y;
				printf("Player coordinates: (%d, %d)\n", x, y);
			}
			y++;
		}
		x++;
	}
}

void	get_and_set_chars_count(t_map *map, char *file_content)
{
	int	collectibles_count;
	int	exit_count;
	int	player_count;

	collectibles_count = 0;
	exit_count = 0;
	player_count = 0;
	while (*file_content)
	{
		if (*file_content == 'C')
			collectibles_count++;
		else if (*file_content == 'E')
			exit_count++;
		else if (*file_content == 'P')
			player_count++;
		file_content++;
	}
	map->collectibles_count = collectibles_count;
	map->exit_count = exit_count;
	map->player_count = player_count;
}
