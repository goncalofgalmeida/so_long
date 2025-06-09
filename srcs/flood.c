/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:20:14 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 14:25:56 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
