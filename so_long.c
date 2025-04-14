/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:32:28 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/11 17:04:09 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		status;

	if (argc != 2)
		return (handle_error_status(ERR_ARGC));
	if (!file_ext_is_valid(argv[1]))
		return (handle_error_status(ERR_INVALID_EXT));
	init_map(&map);
	start_game(&map, argv[1]);
	return (0);
}
