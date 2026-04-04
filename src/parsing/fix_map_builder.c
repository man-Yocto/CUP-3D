/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_map_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:28:54 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 16:28:55 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fix(char **grid)
{
	if (!grid[0])
	{
		free_matrix(grid);
		return (1);
	}
	return (0);
}

int	fix2(int p_count, char **grid)
{
	if (p_count != 1)
	{
		print_error("Invalid player count");
		free_matrix(grid);
		return (1);
	}
	return (0);
}

int	fix3(t_config *config, int j)
{
	if (!config->raw_map_lines[j])
	{
		free_matrix(config->raw_map_lines);
		config->raw_map_lines = NULL;
		print_error("malloc failed");
		return (1);
	}
	return (0);
}
