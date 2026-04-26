/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_flood_fill_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_padding_cells(t_flood_ctx *ctx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ctx->rows)
	{
		j = -1;
		while (++j < ctx->cols)
		{
			if (ctx->map[i][j] == '$')
			{
				ctx->visited[i][j] = 'V';
				ctx->cell->stack[++(*(ctx->cell->top))].i = i;
				ctx->cell->stack[*(ctx->cell->top)].j = j;
			}
		}
	}
}

int	check_neighbors(t_flood_ctx *ctx, int i, int j)
{
	int	dirs[4][2];
	int	idx;
	int	ni;
	int	nj;

	dirs[0][0] = -1;
	dirs[0][1] = 0;
	dirs[1][0] = 1;
	dirs[1][1] = 0;
	dirs[2][0] = 0;
	dirs[2][1] = -1;
	dirs[3][0] = 0;
	dirs[3][1] = 1;
	idx = 0;
	while (idx < 4)
	{
		ni = i + dirs[idx][0];
		nj = j + dirs[idx][1];
		if (is_in_bounds(ni, nj, ctx->rows, ctx->cols))
			if (!process_cell(ctx, ni, nj))
				return (0);
		idx++;
	}
	return (1);
}
