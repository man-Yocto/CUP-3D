/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:11 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:48:36 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_map_block(char **lines, int count, int start)
{
	int	i;

	i = start;
	while (i < count)
	{
		if (is_empty_line(lines[i]))
			return (print_error("empty line in map"));
		if (!is_map_line(lines[i]))
			return (print_error("invalid map block"));
		i++;
	}
	return (0);
}

int	collect_raw_map(char **lines, int count, int start, t_config *config)
{
	int	i;
	int	j;

	if (validate_map_block(lines, count, start))
		return (1);
	config->raw_map_lines = malloc(sizeof(char *) * (count - start + 1));
	if (!config->raw_map_lines)
		return (print_error("malloc failed"));
	i = start;
	j = 0;
	while (i < count)
	{
		config->raw_map_lines[j] = ft_strdup(lines[i]);
		if (!config->raw_map_lines[j])
		{
			free_matrix(config->raw_map_lines);
			config->raw_map_lines = NULL;
			print_error("malloc failed");
			return (1);
		}
		i++;
		j++;
	}
	config->raw_map_lines[j] = NULL;
	config->map_start = start;
	return (0);
}

static int	process_parse_line(char **lines, int count, int *i, t_config *cfg)
{
	int	result;

	if (is_empty_line(lines[*i]))
		(*i)++;
	else if (is_config_line(lines[*i]))
	{
		if (parse_one_config_line(lines[*i], cfg))
			return (1);
		(*i)++;
	}
	else if (!config_complete(cfg))
		return (print_error("map found before full config"));
	else if (is_map_line(lines[*i]))
	{
		result = collect_raw_map(lines, count, *i, cfg);
		return (result);
	}
	return (print_error("unknown identifier in config area"));
}

int	parse_elements(char **lines, int count, t_config *config)
{
	int	i;
	int	result;

	i = 0;
	while (i < count)
	{
		result = process_parse_line(lines, count, &i, config);
		if (result != 0)
			return (result);
	}
	if (!config_complete(config))
		return (print_error("missing texture or color identifiers"));
	return (print_error("missing map"));
}
