/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_flood_fill_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	flood_search(t_flood_ctx *ctx, int *top)
{
	int	i;
	int	j;

	while (*top >= 0)
	{
		i = ctx->cell->stack[*top].i;
		j = ctx->cell->stack[*top].j;
		(*top)--;
		if (!check_neighbors(ctx, i, j))
			return (0);
	}
	return (1);
}

int	iterative_flood_fill(char **map, int rows, int cols,
	char **visited)
{
	t_flood_ctx	ctx;
	t_cell_ctx	cell;
	t_coord		*stack;
	int			top;

	stack = malloc(sizeof(t_coord) * (rows * cols + 1));
	if (!stack)
		return (0);
	top = -1;
	cell.stack = stack;
	cell.top = &top;
	ctx.map = map;
	ctx.visited = visited;
	ctx.rows = rows;
	ctx.cols = cols;
	ctx.cell = &cell;
	push_padding_cells(&ctx);
	if (!flood_search(&ctx, &top))
	{
		free(stack);
		return (0);
	}
	free(stack);
	return (1);
}
