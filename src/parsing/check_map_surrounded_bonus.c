/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_surrounded_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_max_width(char **raw_map, int row_count)
{
	int	max_width;
	int	i;

	max_width = 0;
	i = -1;
	while (++i < row_count)
	{
		if ((int)ft_strlen(raw_map[i]) > max_width)
			max_width = (int)ft_strlen(raw_map[i]);
	}
	return (max_width);
}

int	check_padding_validity(char **raw_map)
{
	char	**padded_map;
	int		row_count;
	int		max_width;
	int		i;

	if (!raw_map)
		return (0);
	row_count = 0;
	while (raw_map[row_count])
		row_count++;
	if (row_count <= 0)
		return (0);
	max_width = get_max_width(raw_map, row_count);
	padded_map = build_padded_map_with_frame(raw_map, row_count,
			max_width);
	if (!padded_map)
		return (0);
	i = is_map_enclosed_with_padding(padded_map, row_count + 2,
			max_width + 2);
	free_matrix(padded_map);
	return (i);
}
