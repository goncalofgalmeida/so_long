/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:28 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/22 11:23:53 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_map	map;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC));
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_EXT));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	init_map(&map);
	start_game(&map, argv[1]);
	mlx_loop(mlx);
	return (0);
}
