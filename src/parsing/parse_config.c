/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:11 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:48:36 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_one_config_line(char *line, t_config *config)
{
	line = skip_spaces(line);
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2))
		return (parse_texture_line(line, config));
	if (!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (parse_texture_line(line, config));
	if (line[0] == 'F' || line[0] == 'C')
		return (parse_color_line(line, config));
	return (print_error("unknown identifier in config area"));
}

int	parse_config_file(const char *filename, t_config *config)
{
	char	**lines;
	int		line_count;
	int		status;

	lines = NULL;
	line_count = 0;
	init_config(config);
	if (!has_cub_extension(filename))
	{
		print_error("invalid file extension");
		return (1);
	}
	if (read_cub_file(filename, &lines, &line_count))
		return (1);
	status = parse_elements(lines, line_count, config);
	free_matrix(lines);
	if (status)
	{
		free_config(config);
		return (1);
	}
	return (0);
}

