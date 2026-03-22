/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:45:43 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:45:44 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     file_validation(t_config *config)
{
        if (path_validation(config) || color_validation(config))
        {
                free_config(config);
                return (1);
        }
        if (map_validation(config))
        {
                free_config(config);
                return (1);
        }
        return (0);
}