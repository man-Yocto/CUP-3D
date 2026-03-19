#include "cub3d.h"

static int	win_close(t_game *game)
{
	cleanup_exit(game);
	return (0);
}

static int	game_loop(t_game *game)
{
	
	update_movement(game);
	update_rotation(game);
	update_mouse_rotation(game);
	render_frame(game);
	update_doors(game);
	draw_crosshair(&game->img);

	return (0);
}

void	start_game(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIN_W / 2, WIN_H / 2);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 4, 1L << 2, mouse_press, game);
	mlx_hook(game->win, 17, 0, win_close, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

void	update_doors(t_game *game)
{
	double	dx;
	double	dy;
	double	dist;
	int		player_cell_x;
	int		player_cell_y;

	if (!game->keys.e || !game->target_door)
		return ;

	dx = game->target_door->x - game->player.x;
	dy = game->target_door->y - game->player.y;
	dist = sqrt(dx * dx + dy * dy);
	
	player_cell_x = (int)game->player.x;
	player_cell_y = (int)game->player.y;
	
	if (game->target_door->is_open)
	{
		if (player_cell_x != game->target_door->x || player_cell_y != game->target_door->y)
		{
			if (dist >= 0.3)
				game->target_door->is_open = !game->target_door->is_open;
		}
	}
	else
	{
		if (dist < 2.0)
			game->target_door->is_open = !game->target_door->is_open;
	}
	game->keys.e = 0;
}