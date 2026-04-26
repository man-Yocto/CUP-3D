/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_padding_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**allocate_padded_map(int rows, int cols)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(cols + 1);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		ft_memset(map[i], '.', cols);
		map[i][cols] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	fill_top_bottom_rows(char **padded, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
		padded[0][i++] = '$';
	i = 0;
	while (i < cols)
		padded[rows - 1][i++] = '$';
}

void	fill_middle_row(char **padded, char *raw, int idx, int cols)
{
	int	j;
	int	raw_len;

	raw_len = ft_strlen(raw);
	padded[idx][0] = '$';
	j = 0;
	while (j < raw_len)
	{
		padded[idx][j + 1] = raw[j];
		j++;
	}
	while (j + 1 < cols - 1)
	{
		j++;
		padded[idx][j] = '$';
	}
	padded[idx][cols - 1] = '$';
}

void	fill_middle_rows(char **padded, char **raw_map, int rows, int cols)
{
	int	i;

	i = 1;
	while (i <= rows)
	{
		fill_middle_row(padded, raw_map[i - 1], i, cols);
		i++;
	}
}
