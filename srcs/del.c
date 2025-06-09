#include "../so_long.h"

// delete
void	print_map(t_map map)
{
	int		y;
	int		x;

	printf("Map:\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("%c", map.matrix[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

// delete
void	print_flood(t_map map)
{
	int		y;
	int		x;

	printf("Flooded map:\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("%c", map.flood[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
