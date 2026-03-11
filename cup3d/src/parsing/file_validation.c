#include "cub3d.h"

int	check_map_validity(t_config *config)
{
	t_flood	flood;

	flood.found_c = 0;
	flood.found_e = 0;
	flood_fill(config->map, config->p_pos[0], config->p_pos[1], &flood);
	if (flood.found_e == 0)
	{
		print_error("Error: Exit not reachable from player");
		return (0);
	}
	return (1);
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
	if (!check_map_validity(config))
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

int	make_and_padding(t_config *config)
{
	int		p_count;
	size_t	i;
	size_t	line_c;
	size_t	j;
	char	*line;
	char	c;

	p_count = 0;
	i = 0;
	line_c = 1;
	line = malloc(config->width + 3);
	if (!line)
		return (print_error("Error with malloc!"));
	i = 0;
	while (i < config->width + 2)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	config->map[0] = line;
	i = 0;
	while (config->raw_map_lines[i])
	{
		j = 0;
		line = malloc(config->width + 3);
		if (!line)
			return (print_error("Error with malloc!"));
		line[0] = ' ';
		while (config->raw_map_lines[i][j]
			&& config->raw_map_lines[i][j] != '\n')
		{
			c = config->raw_map_lines[i][j];
			line[j + 1] = c;
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				p_count++;
				config->p_pos[0] = j + 1;
				config->p_pos[1] = line_c;
				config->p_faced = c;
			}
			j++;
		}
		while (j < config->width)
		{
			line[j + 1] = ' ';
			j++;
		}
		line[j + 1] = ' ';
		line[j + 2] = '\0';
		config->map[line_c] = line;
		line_c++;
		i++;
	}
	line = malloc(config->width + 3);
	if (!line)
		return (print_error("Error with malloc!"));
	i = 0;
	while (i < config->width + 2)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	config->map[line_c] = line;
	config->map[line_c + 1] = NULL;
	config->height = line_c + 1;
	if (p_count != 1)
		return (print_error("Error\nInvalid player count"));
	return (0);
}

int check_characters(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			int c = config->map[i][j];
			if (c != ' ' && c != '0' && c != '1' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W' && c != 'C')
				return (print_error("Error\nInvalid character in map"));
			j++;
		}
		i++;
	}
	return (0);
}

int map_validation(t_config *config)
{
	size_t	max_len;

	if (config->raw_map_lines == NULL)
		return (0);
	max_len = getm_length(config->raw_map_lines);
	config->width = max_len;
	if (make_and_padding(config) || check_characters(config))
		return (1);
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

int path_validation(t_config *config)
{
	if (access(config->no_path, F_OK) == -1)
	{
		printf("Error: North texture file not found\n");
		return (1);
	}
	if (access(config->so_path, F_OK) == -1)
	{
		printf("Error: South texture file not found\n");
		return (1);
	}
	if (access(config->we_path, F_OK) == -1)
	{
		printf("Error: West texture file not found\n");
		return (1);
	}
	if (access(config->ea_path, F_OK) == -1)
	{
		printf("Error: East texture file not found\n");
		return (1);
	}
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