#include "cub3d.h"

static void	init_textures_arr(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->tex[i].img = NULL;
		game->tex[i].addr = NULL;
		game->tex[i].width = 0;
		game->tex[i].height = 0;
		game->tex[i].bpp = 0;
		game->tex[i].line_len = 0;
		game->tex[i].endian = 0;
		i++;
	}
}

void	init_game_structs(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->floor_color = 0;
	game->ceil_color = 0;
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	game->img.img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
	init_textures_arr(game);
	init_config(&game->config);
}
