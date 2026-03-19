#include "cub3d.h"

static void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	update_rotation(t_game *game)
{
	if (game->keys.left)
		rotate_player(&game->player, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(&game->player, ROT_SPEED);
}

void	update_mouse_rotation(t_game *game)
{
	int		mouse_x;
	int		mouse_y;
	int		center_x;
	int		center_y;
	int		delta_x;
	double	angle;
 
	if (!game->mouse_locked)
		return ;
	center_x = WIN_W / 2;
	center_y = WIN_H / 2;
	mlx_mouse_get_pos(game->mlx, game->win, &mouse_x, &mouse_y);
	delta_x = mouse_x - center_x;
	if (delta_x > -2 && delta_x < 2)
	{
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
		return ;
	}
	angle = delta_x * MOUSE_SENSITIVITY;
	rotate_player(&game->player, angle);
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
}
 
void	draw_crosshair(t_img *img)
{
	int	center_x;
	int	center_y;
	int	color;
	int	size;
	int	x;
	int	y;
 
	center_x = WIN_W / 2;
	center_y = WIN_H / 2;
	color = 0x00FF00;
	size = 10;
	x = center_x - size;
	while (x <= center_x + size)
	{
		put_pixel(img, x, center_y, color);
		x++;
	}
	y = center_y - size;
	while (y <= center_y + size)
	{
		put_pixel(img, center_x, y, color);
		y++;
	}
	put_pixel(img, center_x, center_y, 0xFFFFFF);
}

void	init_mouse_system(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIN_W / 2, WIN_H / 2);
}

