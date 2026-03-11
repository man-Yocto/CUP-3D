#include "cub3d.h"

int	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	map[y][x] = 'V';
	if (flood_fill(map, x + 1, y))
		return (1);
	if (flood_fill(map, x - 1, y))
		return (1);
	if (flood_fill(map, x, y + 1))
		return (1);
	if (flood_fill(map, x, y - 1))
		return (1);
	return (0);
}

int	check_map_validity(t_config *config)
{
	if (flood_fill(config->map, config->p_pos[0], config->p_pos[1]))
	{
		print_error("Error: Map is not enclosed by walls");
		return (0);
	}
	return (1);
}