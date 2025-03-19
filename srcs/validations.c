#include "../libft/libft.h"
#include "../so_long.h"

int	file_ext_is_valid(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
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
//alterar param para o **map
int	map_content_is_valid(char *file_name)
{
	if (file_name)
	{
		return 1;
	}
	return 0;
}

int	is_map_valid(char *file_name)
{
	//char	**map;

	//map = parse_map();
	if (!map_content_is_valid(file_name))
		return (0);
	return (1);
}
