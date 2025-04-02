/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:27:49 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/02 17:14:21 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Counts number of \n and adds 1 to count the last line
int	get_map_height(char *file_content)
{
	int	height;

	height = 0;
	while (*file_content)
	{
		if (*file_content == '\n')
			height++;
		file_content++;
	}
	height++;
	printf("CALCULATED HEIGHT: %i\n", height);
	return (height);
}

int	get_map_width(char *file_content)
{
	int	width;

	width = 0;
	while (file_content[width] && file_content[width] != '\n')
		width++;
	printf("CALCULATED WIDTH: %i\n", width);
	return (width);
}
