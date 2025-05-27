/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:27:49 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/27 11:46:17 by g24force         ###   ########.fr       */
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
				printf("Player coordinates: (%d, %d)\n", x, y); // delete
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

int	is_rectangular(t_map *map) {
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
	int		x;
	int		y;

	y = 0;
	while (map->matrix[0][y])
	{
		if (map->matrix[0][y] != '1' || map->matrix[map->height - 1][y] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (x < map->height) //map->matrix[x][0]
	{
		if (map->matrix[x][0] != '1' || map->matrix[x][map->width - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

// delete
void	print_map(t_map map)
{
	int		x;
	int		y;

	x = 0;
	while (x < map.height)
	{
		y = 0;
		while (y < map.width)
		{
			printf("%c", map.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}
