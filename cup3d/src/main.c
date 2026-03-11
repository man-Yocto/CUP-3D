#include "cub3d.h"

static void print_config(t_config *c)
{
	int i;

	printf("%s\n", c->no_path);
	printf("%s\n", c->so_path);
	printf("%s\n", c->we_path);
	printf("%s\n", c->ea_path);

	printf("Floor RGB: %d %d %d\n",
		c->floor_rgb[0], c->floor_rgb[1], c->floor_rgb[2]);

	printf("Ceiling RGB: %d %d %d\n",
		c->ceiling_rgb[0], c->ceiling_rgb[1], c->ceiling_rgb[2]);

	printf("\nMap:\n");

	i = 0;
	while (c->raw_map_lines[i])
	{
		printf("%s\n", c->raw_map_lines[i]);
		i++;
	}
}

//we have an error in the map reading part, we need if like their s a line with spaces on it take it and also if their is a new lines and after them i put a spaces we taking that
//we will draw in the raw_map_lines map and the padding one is for only the checking
int	main(int argc, char **argv)
{
	t_config	config;

	if (argc != 2)
	{
		printf("Usage: ./cub3D map.cub\n");
		return (1);
	}
	if (parse_config_file(argv[1], &config))
		return (1);
	if(file_validation(&config))
		return (1);

	print_config(&config);

	free_config(&config);
    

	return (0);
}