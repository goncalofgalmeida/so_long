/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:35:51 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 18:24:02 by gjose-fr         ###   ########.fr       */
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

void	get_and_set_map(t_game *game, char *file_path)
{
	t_map	*map;
	char	*file_content;

	map = &(game->map);
	file_content = get_file_content(file_path);
	if (!file_content)
	{
		free(file_content);
		exit_game(game, ERR_OPENING_FILE, "Error opening file.");
	}
	if (!map_content_is_valid(file_content))
	{
		free(file_content);
		exit_game(game, ERR_INVALID_CHAR, "Invalid character found.");
	}
	map->height = get_map_height(file_content);
	map->width = get_map_width(file_content);
	map->matrix = ft_split(file_content, '\n');
	map->flood = ft_split(file_content, '\n');
	get_and_set_chars_count(map, file_content);
	free(file_content);
}

void	start_game(t_game *game, char *file_path)
{
	t_map	*map;

	map = &(game->map);
	get_and_set_map(game, file_path);
	get_and_set_player_coords(map);
	parse_map(game);
}
