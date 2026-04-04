/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:56:13 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/05 00:53:57 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dup_clean_line(char *line)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	while (line[len] && line[len] != '\n' && line[len] != '\r')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = line[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	count_file_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	process_file_line(char **lines, int count, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines[i] = dup_clean_line(line);
		free(line);
		if (!lines[i])
			break ;
		i++;
	}
	lines[i] = NULL;
	return (i);
}

int	fill_file_lines(const char *filename, char **lines, int count)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = process_file_line(lines, count, fd);
	drain_gnl(fd);
	close(fd);
	return (i == count);
}
