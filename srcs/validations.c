/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:38:25 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/08 17:34:20 by g24force         ###   ########.fr       */
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

void	flood_fill(char **flood, int y, int x)
{
	if (y < 0 || x < 0 || flood[y][x] == '1' || flood[y][x] == 'F'
		|| flood[y][x] == 'e')
		return ;
	if (flood[y][x] == 'E')
	{
		flood[y][x] = 'e';
		return ;
	}
	flood[y][x] = 'F';
	flood_fill(flood, y + 1, x);
	flood_fill(flood, y - 1, x);
	flood_fill(flood, y, x + 1);
	flood_fill(flood, y, x - 1);
}

int	is_winnable(char **flood)
{
	int	y;
	int	x;


	y = 0;
	while (flood[y])
	{
		x = 0;
		while (flood[y][x])
		{
			if (flood[y][x] == 'C' || flood[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
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
	flood_fill(map->flood, map->player.y_coord, map->player.x_coord);
	print_map(*map); // delete
	print_flood(*map); // delete
	if (!is_winnable(map->flood))
		handle_error_status(ERR_MAP_NOT_WIN);
}
