/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:13 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 00:56:15 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fix6(char **lines, int count, int *i, t_config *config)
{
	int	result;

	if (!config_complete(config))
	{
		print_error("map found before full config");
		return (1);
	}
	else if (is_map_line(lines[*i]))
	{
		result = collect_raw_map(lines, count, *i, config);
		if (result == 0)
			return (2);
		return (result);
	}
	else
	{
		print_error("unknown identifier in config area");
		return (1);
	}
}

static int	fix5(char **lines, int count, int *i, t_config *config)
{
	int	result;

	if (is_empty_line(lines[*i]))
		(*i)++;
	else if (is_config_line(lines[*i]))
	{
		if (parse_one_config_line(lines[*i], config))
			return (1);
		(*i)++;
	}
	else
	{
		result = fix6(lines, count, i, config);
		if (result != 0)
			return (result);
	}
	return (0);
}

int	fix4(char **lines, int count, t_config *config)
{
	int	i;
	int	result;

	i = 0;
	while (i < count)
	{
		result = fix5(lines, count, &i, config);
		if (result != 0)
			return (result);
	}
	return (-1);
}

int	fix7(int count)
{
	if (count < 0)
	{
		print_error("failed to open file");
		return (1);
	}
	if (count == 0)
	{
		print_error("empty file");
		return (1);
	}
	return (0);
}
