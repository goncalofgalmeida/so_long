/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:35:51 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/03 18:17:50 by g24force         ###   ########.fr       */
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
	if (!file_content)
		handle_error_status(67); // error reading file, change code later
	if (!map_content_is_valid(file_content))
		handle_error_status(ERR_INVALID_CHAR);
	map->height = get_map_height(file_content);
	map->width = get_map_width(file_content);
	map->matrix = ft_split(file_content, '\n');
	map->flood = ft_split(file_content, '\n');
	get_and_set_chars_count(map, file_content);
}

void	start_game(t_map *map, char *file_path)
{
	get_and_set_map(map, file_path);
	get_and_set_player_coords(map);
	parse_map(map);
}
