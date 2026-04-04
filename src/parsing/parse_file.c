/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:13 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:48:36 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_cub_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

int	read_cub_file(const char *filename, char ***lines, int *line_count)
{
	int	count;

	count = count_file_lines(filename);
	if (count < 0)
		return (print_error("failed to open file"));
	if (count == 0)
		return (print_error("empty file"));
	*lines = malloc(sizeof(char *) * (count + 1));
	if (!*lines)
		return (print_error("malloc failed"));
	if (!fill_file_lines(filename, *lines, count))
	{
		free_matrix(*lines);
		*lines = NULL;
		return (print_error("failed to read file"));
	}
	*line_count = count;
	return (0);
}

