/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_map_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:24:08 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:32:56 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
