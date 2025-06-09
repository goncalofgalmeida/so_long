/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:27:49 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 18:27:56 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_ext_is_valid(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (0);
	if (file_name[len - 1] != 'r')
		return (0);
	if (file_name[len - 2] != 'e')
		return (0);
	if (file_name[len - 3] != 'b')
		return (0);
	if (file_name[len - 4] != '.')
		return (0);
	if (file_name[len - 5] && file_name[len - 5] == '/')
		return (0);
	return (1);
}

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
	int	y;
	int	x;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] == 'P')
			{
				map->player.y_coord = y;
				map->player.x_coord = x;
			}
			x++;
		}
		y++;
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
