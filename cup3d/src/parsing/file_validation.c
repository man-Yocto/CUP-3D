#include "cub3d.h"

void	free_map(t_config *config)
{
	size_t	i;

	if (!config->map)
		return ;
	i = 0;
	while (config->map[i])
	{
		free(config->map[i]);
		i++;
	}
	free(config->map);
	config->map = NULL;
}

int file_validation(t_config *config)
{
	if (path_validation(config) || color_validation(config))
	{
		free_config(config);
		return (1);
	}
	if (map_validation(config))
	{
		free_config(config);
		return (1);
	}
	return (0);
}

size_t getm_length(char **matrix)
{
	size_t	len;
	size_t	m_len;
	size_t	line_len;

	len = 0;
	m_len = 0;
	while (matrix[len])
	{
		line_len = ft_strlen(matrix[len]);
		if (line_len > 0 && matrix[len][line_len - 1] == '\n')
			line_len--;
		if (line_len > m_len)
			m_len = line_len;
		len++;
	}
	return (m_len);
}

static char	*make_empty_line(size_t width)
{
	char	*line;
	size_t	i;

	line = malloc(width + 3);
	if (!line)
		return (NULL);
	i = 0;
	while (i < width + 2)
		line[i++] = ' ';
	line[i] = '\0';
	return (line);
}

static char	*make_content_line(char *raw, size_t width, int *p_pos,
		char *p_dir, size_t row, int *p_count)
{
	char	*line;
	size_t	j;

	line = malloc(width + 3);
	if (!line)
		return (NULL);
	line[0] = ' ';
	j = 0;
	while (raw[j] && raw[j] != '\n')
	{
		line[j + 1] = raw[j];
		if (raw[j] == 'N' || raw[j] == 'S'
			|| raw[j] == 'E' || raw[j] == 'W')
		{
			if (p_pos && p_dir)
			{
				(*p_count)++;
				p_pos[0] = j + 1;
				p_pos[1] = row;
				*p_dir = raw[j];
			}
		}
		j++;
	}
	while (j < width)
		line[++j] = ' ';
	line[j + 1] = ' ';
	line[j + 2] = '\0';
	return (line);
}

char	**build_padded_map(char **raw_lines, size_t width, int *p_pos,
		char *p_dir)
{
	char	**grid;
	size_t	line_count;
	size_t	i;
	int		p_count;

	line_count = 0;
	while (raw_lines && raw_lines[line_count])
		line_count++;
	grid = malloc(sizeof(char *) * (line_count + 3));
	if (!grid)
		return (NULL);
	p_count = 0;
	grid[0] = make_empty_line(width);
	if (!grid[0])
		return (free(grid), NULL);
	i = 0;
	while (i < line_count)
	{
		grid[i + 1] = make_content_line(raw_lines[i], width, p_pos,
				p_dir, i + 1, &p_count);
		if (!grid[i + 1])
			return (free(grid), NULL);
		i++;
	}
	grid[i + 1] = make_empty_line(width);
	if (!grid[i + 1])
		return (free(grid), NULL);
	grid[i + 2] = NULL;
	if (p_count != 1)
		return (print_error("Error\nInvalid player count"), free_matrix(grid), NULL);
	return (grid);
}



int check_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{	
		j = 0;
		while (map[i][j])
		{
			int c = map[i][j];
			if (c != ' ' && c != '0' && c != '1' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W' && c != 'C')
				return (print_error("Error\nInvalid character in map"));
			j++;
		}
		i++;
	}
	return (0);
}

int	map_validation(t_config *config)
{
	size_t	max_len;
	size_t	i;
	char	**temp_map;

	if (config->raw_map_lines == NULL)
		return (0);
	max_len = getm_length(config->raw_map_lines);
	config->width = max_len;
	config->height = 0;
	temp_map = build_padded_map(config->raw_map_lines, config->width,
		config->p_pos, &config->p_faced);
	if (!temp_map)
		return (1);
	if (check_characters(temp_map))
	{
		free_matrix(temp_map);
		return (1);
	}
	if (!check_map_validity(temp_map, config->p_pos[0], config->p_pos[1]))
	{
		free_matrix(temp_map);
		return (1);
	}
	free_matrix(temp_map);
	config->map = build_padded_map(config->raw_map_lines, config->width,
		config->p_pos, &config->p_faced);
	if (!config->map)
		return (1);
	config->map_data.grid = config->map;
	config->map_data.width = config->width;
	i = 0;
	while (config->map && config->map[i])
		i++;
	config->map_data.height = i;
	printf("Map validation passed\n");
	return (0);
}

int color_validation(t_config *config)
{
	if (config->floor_rgb[0] < 0 || config->floor_rgb[0] > 255
		|| config->floor_rgb[1] < 0 || config->floor_rgb[1] > 255
		|| config->floor_rgb[2] < 0 || config->floor_rgb[2] > 255)
	{
		printf("Error: Floor RGB values must be between 0 and 255\n");
		return (1);
	}
	if (config->ceiling_rgb[0] < 0 || config->ceiling_rgb[0] > 255
		|| config->ceiling_rgb[1] < 0 || config->ceiling_rgb[1] > 255
		|| config->ceiling_rgb[2] < 0 || config->ceiling_rgb[2] > 255)
	{
		printf("Error: Ceiling RGB values must be between 0 and 255\n");
		return (1);
	}
	return (0);
}

// because not having xpm files i commented them :)
int path_validation(t_config *config)
{
	// if (access(config->no_path, F_OK) == -1)
	// {
	// 	printf("Error: North texture file not found\n");
	// 	return (1);
	// }
	// if (access(config->so_path, F_OK) == -1)
	// {
	// 	printf("Error: South texture file not found\n");
	// 	return (1);
	// }
	// if (access(config->we_path, F_OK) == -1)
	// {
	// 	printf("Error: West texture file not found\n");
	// 	return (1);
	// }
	// if (access(config->ea_path, F_OK) == -1)
	// {
	// 	printf("Error: East texture file not found\n");
	// 	return (1);
	// }
    //not sure but i think its good to be here
	if (config->so_path == config->no_path
		|| config->we_path == config->no_path
		|| config->ea_path == config->no_path
		|| config->we_path == config->so_path
		|| config->ea_path == config->so_path
		|| config->ea_path == config->we_path)
	{
		printf("Error: Texture paths must be unique\n");
		return (1);
	}
	return (0);
}