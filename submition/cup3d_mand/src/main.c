#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_game		game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D map.cub"));
	if (parse_config_file(argv[1], &config))
		return (1);
	if (file_validation(&config))
		return (1);
	if (init_game(&game, &config))
		return (1);
	start_game(&game);
	return (0);
}
