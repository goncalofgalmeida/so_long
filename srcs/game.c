/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:35:51 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/09 15:24:55 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_file_content(char *file_path)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*file_content;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file_content = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!file_content)
			file_content = ft_strdup(line);
		else
		{
			temp = ft_strjoin(file_content, line);
			free(file_content);
			file_content = temp;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file_content);
}

void	get_and_set_map(t_map *map, char *file_path)
{
	char	*file_content;

	file_content = get_file_content(file_path);
	map->height = get_map_height(file_content);
	map->width = get_map_width(file_content);
	map->matrix = ft_split(file_content, '\n');
}

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

void	start_game(t_map *map, char *file_path)
{
	// arranjar maneira de ver a posicão de 'p' na matriz e guardar as coords em t_player
	map->player->x_coord = 1;
	map->player->y_coord = 1;
	get_and_set_map(map, file_path);
	print_map(*map);
}
