/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_flood_fill_helpers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 12:00:00 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/12 12:00:00 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_playable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_passable(char c)
{
	return (c == '$' || c == ' ');
}

int	is_in_bounds(int i, int j, int rows, int cols)
{
	return (i >= 0 && i < rows && j >= 0 && j < cols);
}

int	process_cell(t_flood_ctx *ctx, int i, int j)
{
	if (ctx->visited[i][j] == 'V')
		return (1);
	if (is_playable(ctx->map[i][j]))
		return (0);
	if (ctx->map[i][j] == '1')
		ctx->visited[i][j] = 'V';
	else if (is_passable(ctx->map[i][j]))
	{
		ctx->visited[i][j] = 'V';
		ctx->cell->stack[++(*(ctx->cell->top))].i = i;
		ctx->cell->stack[*(ctx->cell->top)].j = j;
	}
	else
		ctx->visited[i][j] = 'V';
	return (1);
}
