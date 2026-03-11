#include "cub3d.h"

void	flood_fill(char **map, int x, int y, t_flood *flood)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		flood->found_c++;
	if (map[y][x] == 'E')
		flood->found_e = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, flood);
	flood_fill(map, x - 1, y, flood);
	flood_fill(map, x, y + 1, flood);
	flood_fill(map, x, y - 1, flood);
}

int	validate_map_enclosed(char **map, int width, int height,
	int start_x, int start_y)
{
	t_flood	flood;

	(void)width;
	(void)height;
	flood.found_c = 0;
	flood.found_e = 0;
	flood_fill(map, start_x, start_y, &flood);
	if (flood.found_e == 1)
		return (1);
	return (0);
}