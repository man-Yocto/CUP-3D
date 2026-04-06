#include "cub3d.h"


char	**fix_free_grid(char **grid)
{
	free_matrix(grid);
	return (NULL);
}

char	**fix_error_free_grid(char **grid, char *msg)
{
	print_error(msg);
	free_matrix(grid);
	return (NULL);
}
