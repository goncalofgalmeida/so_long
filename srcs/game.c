#include "../so_long.h"
/* 
11111111111111111111
10000000000000000001
10000000000000000001
10000000000000000001
11111111111111111111
*/

char **	create_map(void)
{
	char	**matrix;
	int 	height = 5;
	int 	width = 20;

	matrix = (char **)malloc(sizeof(char *) * height);
	
	int i = 0;
	while (i < height)
	{
		matrix[i] = (char *)malloc(sizeof(char) * width);
		i++;
	}
	return matrix;
}

// passar struct do map, para ter o conteudo, altura e largura
void	populate_map(t_map *map_ptr)
{
	char 	**matrix = map_ptr->matrix;
	int 	height = 5;
	int 	width = 20;
	int 	x;
	int 	y;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			matrix[x][y] = '1';
			y++;
		}
		x++;
	}
	
}

int main(void)
{
	t_map map;

	map.matrix = create_map();
	populate_map(&map);
	int 	x;
	int 	y;

	x = 0;
	while (x < 5)
	{
		y = 0;
		while (y < 20)
		{
			printf("%c", map.matrix[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}

	return 0;
}