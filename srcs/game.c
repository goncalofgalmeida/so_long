/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:35:51 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/02 14:30:12 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_map(t_map *map)
{
	int	i;

	map->matrix = (char **)malloc(sizeof(char *) * map->height);
	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = (char *)malloc(sizeof(char) * map->width);
		i++;
	}
}

//perceber como fazer chegar o file path ate aqui
char	*get_file_content(void)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*file_content;

	fd = open("./test.ber", O_RDONLY);
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

void	populate_map(t_map *map)
{
	char	*file_content;

	file_content = get_file_content();
	map->matrix = ft_split(file_content, '\n');
}

// adicionar o file path e passa lo para a populate map
void	start_game(t_map *map, char *file_path)
{
	int		x;
	int		y;

	create_map(map);
	populate_map(map);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			printf("%c", map->matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}
