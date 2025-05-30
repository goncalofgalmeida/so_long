/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:32:19 by g24force          #+#    #+#             */
/*   Updated: 2025/05/30 01:17:33 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

// rename file later if needed, maybe free_and_exit

int		handle_close_game(t_game *game)
{
	// free stuff
	(void)game; // delete line
	exit(0);
	return (0);
}

/* free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->matrix)
	{
		while (i < map->height)
		{
			free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	if (map->player)
		free(map->player);
} */
