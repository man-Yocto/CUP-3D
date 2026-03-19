#include "cub3d.h"

int is_closed_door(int x, int y, char**map, t_game *game)
{
	if (map[y][x] != 'D')
		return (0);
	return (!is_door_open(x, y, game->config.doors, game->config.door_count));
}
static void	apply_move(t_game *game, double dx, double dy)
{
	t_player	*p;
	char		**map;

	p = &game->player;
	map = game->config.map;
	if (map[(int)p->y][(int)(p->x + dx)] != '1' && !is_closed_door((int)(p->x + dx), (int)p->y, map, game))
		p->x += dx;
	if (map[(int)(p->y + dy)][(int)p->x] != '1' && !is_closed_door((int)p->x, (int)(p->y + dy), map, game))
		p->y += dy;
}

void	update_movement(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (game->keys.w)
		apply_move(game, p->dir_x * MOVE_SPEED, p->dir_y * MOVE_SPEED);
	if (game->keys.s)
		apply_move(game, -p->dir_x * MOVE_SPEED, -p->dir_y * MOVE_SPEED);
	if (game->keys.a)
		apply_move(game, p->dir_y * MOVE_SPEED, -p->dir_x * MOVE_SPEED);
	if (game->keys.d)
		apply_move(game, -p->dir_y * MOVE_SPEED, p->dir_x * MOVE_SPEED);
}
