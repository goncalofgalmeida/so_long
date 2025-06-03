/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:27:49 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/03 18:19:14 by g24force         ###   ########.fr       */
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
				printf("Player coordinates: (%d, %d)\n", y, x); // delete
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
	while (y < map->height) //map->matrix[x][0]
	{
		if (map->matrix[y][0] != '1' || map->matrix[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

// delete
void	print_map(t_map map)
{
	int		y;
	int		x;

	printf("Map:\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("%c", map.matrix[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

// delete
void	print_flood(t_map map)
{
	int		y;
	int		x;

	printf("Flooded map:\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("%c", map.flood[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
