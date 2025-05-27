/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:38:25 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/23 20:27:11 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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
	return (1);
}

int	map_content_is_valid(char *file_content)
{
	char	*valid_chars;

	valid_chars = "10PCE\n";
	while (*file_content)
	{
		if (!ft_strchr(valid_chars, *file_content))
			return (0);
		file_content++;
	}
	return (1);
}

void check_chars_count(t_map *map)
{
	if (map->player_count != 1)
		handle_error_status(ERR_MULTIPLE_STARTS);
	if (map->exit_count != 1)
		handle_error_status(ERR_MULTIPLE_EXITS);
	if (map->collectibles_count < 1)
		handle_error_status(ERR_NO_COLLECTIBLES);
}

//acho que posso passar aqui o mapa direto, não pointer
void	parse_map(t_map *map)
{
	if (!is_rectangular(map))
		handle_error_status(ERR_INVALID_MAP_PROPORTIONS);
	if (!is_surrounded_by_walls(map))
		handle_error_status(ERR_MISSING_WALL);
	if (map->player_count != 1)
		handle_error_status(ERR_MULTIPLE_STARTS);
	if (map->exit_count != 1)
		handle_error_status(ERR_MULTIPLE_EXITS);
	if (map->collectibles_count <= 0)
		handle_error_status(ERR_NO_COLLECTIBLES);
	// check if map is winnable 
}
