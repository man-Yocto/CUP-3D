#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_map
{
    char    **grid;
    int        width;
    int        height;
    int        player_x;
    int        player_y;
    char    player_dir;
}    t_map;

typedef struct s_config
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**raw_map_lines;
	char	**map;
	int		map_start;
	size_t	width;
	size_t	height;
	int		p_pos[2];
	int		p_count;
	char	p_faced;
	t_maap	map_data;
}	t_config;

char	*get_next_line(int fd);

void	init_config(t_config *config);
void	free_config(t_config *config);
void	free_matrix(char **matrix);
int		print_error(char *msg);

int		has_cub_extension(const char *filename);
int		read_cub_file(const char *filename, char ***lines, int *line_count);

char	*skip_spaces(char *str);
int		is_empty_line(const char *line);
int		is_map_line(char *line);
int		is_config_line(char *line);
int		config_complete(t_config *config);

int		parse_texture_line(char *line, t_config *config);
int		parse_color_line(char *line, t_config *config);

int		collect_raw_map(char **lines, int count,
			int start, t_config *config);
int		parse_elements(char **lines, int count, t_config *config);
int		parse_config_file(const char *filename, t_config *config);

void	drain_gnl(int fd);
int		file_validation(t_config *config);
int		map_validation(t_config *config);
int		color_validation(t_config *config);
int		path_validation(t_config *config);
int		flood_fill(char **map, int x, int y);
int		check_map_validity(t_config *config);

#endif