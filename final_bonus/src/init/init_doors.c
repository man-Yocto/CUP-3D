#include "cub3d.h"

int	init_doors(t_game *game)
{
    int	door_count;
    int	i;

    door_count = count_doors(game->config.map_data.grid);
    if (door_count == 0)
    {
        game->config.doors = NULL;
        game->config.target_door = NULL;
        return (0);
    }
    game->config.doors = malloc(sizeof(t_door) * door_count);
    if (!game->config.doors)
        return (print_error("Memory allocation failed for doors"), 1);
    i = 0;
    game->config.door_count = door_count;
    for (int y = 0; game->config.map_data.grid[y]; y++)
    {
        for (int x = 0; game->config.map_data.grid[y][x]; x++)
        {
            if (game->config.map_data.grid[y][x] == 'D')
            {
                game->config.doors[i].x = x;
                game->config.doors[i].y = y;
                game->config.doors[i].is_open = 0;
                game->config.doors[i].is_target = 0;
                i++;
            }
        }
    }
    game->config.target_door = NULL;
    return (0);
}

int	count_doors(char **map)
{
    int	count;
    int	y;
    int	x;

    count = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'D')
                count++;
            x++;
        }
        y++;
    }
    return (count);
}