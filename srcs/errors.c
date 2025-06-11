/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:39:41 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/11 12:50:38 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_game *game, int status, char *msg)
{
	if (msg)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putendl_fd(msg, 1);
	}
	if (status == 0)
		ft_putendl_fd("\nGame over! You won!", 1);
	free_all(game);
	exit(status);
}
