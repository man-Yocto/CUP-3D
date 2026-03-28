/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:55:48 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/28 00:55:49 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_xpm_extension(char *path)
{
	size_t	len;
	int		i;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5)
		return (0);
	i = !(ft_strncmp(path + len - 4, ".xpm", 4));
	return (i);
}

static int	validate_one_texture(char *path, char *msg)
{
	if (!path)
	{
		print_error("missing texture path");
		return (1);
	}
	if (!has_xpm_extension(path))
	{
		print_error("texture file must have .xpm extension");
		return (1);
	}
	if (access(path, F_OK) == -1)
	{
		print_error(msg);
		return (1);
	}
	if (access(path, R_OK) == -1)
	{
		print_error("texture file is not readable");
		return (1);
	}
	return (0);
}

int	color_validation(t_config *config)
{
	if (config->floor_rgb[0] < 0 || config->floor_rgb[0] > 255
		|| config->floor_rgb[1] < 0 || config->floor_rgb[1] > 255
		|| config->floor_rgb[2] < 0 || config->floor_rgb[2] > 255)
	{
		print_error("Floor RGB values must be between 0 and 255");
		return (1);
	}
	if (config->ceiling_rgb[0] < 0 || config->ceiling_rgb[0] > 255
		|| config->ceiling_rgb[1] < 0 || config->ceiling_rgb[1] > 255
		|| config->ceiling_rgb[2] < 0 || config->ceiling_rgb[2] > 255)
	{
		print_error("Ceiling RGB values must be between 0 and 255");
		return (1);
	}
	return (0);
}

int	path_validation(t_config *config)
{
	if (validate_one_texture(config->no_path, "North texture file not found"))
		return (1);
	if (validate_one_texture(config->so_path, "South texture file not found"))
		return (1);
	if (validate_one_texture(config->we_path, "West texture file not found"))
		return (1);
	if (validate_one_texture(config->ea_path, "East texture file not found"))
		return (1);
	return (0);
}
