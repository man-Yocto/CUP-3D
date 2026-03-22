/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:46:48 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:46:48 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    drain_gnl(int fd)
{
        char *line;

        line = get_next_line(fd);
        while (line)
        {
                free(line);
                line = get_next_line(fd);
        }
}