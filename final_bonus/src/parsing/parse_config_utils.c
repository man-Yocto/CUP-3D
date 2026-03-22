/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:48:53 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:48:54 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     process_config_line(char **lines, int count, int i, t_config *config)
{
        if (is_empty_line(lines[i]))
                return (-1);
        if (is_config_line(lines[i]))
                return (parse_one_config_line(lines[i], config));
        if (!config_complete(config))
                return (print_error("map found before full config"));
        if (is_map_line(lines[i]))
                return (collect_raw_map(lines, count, i, config));
        return (print_error("unknown identifier in config area"));
}