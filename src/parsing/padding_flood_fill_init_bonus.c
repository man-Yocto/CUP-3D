/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_flood_fill_init_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	int	di[4];
	int	dj[4];
	int	idx;

	di[0] = -1;
	di[1] = 1;
	di[2] = 0;
	di[3] = 0;
	dj[0] = 0;
	dj[1] = 0;
	dj[2] = -1;
	dj[3] = 1;
	idx = -1;
	while (++idx < 4)
	{
		if (is_in_bounds(i + di[idx], j + dj[idx], ctx->rows,
				ctx->cols))
			if (!process_cell(ctx, i + di[idx], j + dj[idx]))
				return (0);
	}
	return (1);
}
