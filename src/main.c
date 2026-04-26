/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:26:07 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/04/06 18:26:08 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_game		game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D map.cub"));
	if (parse_config_file(argv[1], &config))
		return (1);
	if (file_validation(&config))
		return (1);
	if (init_game(&game, &config))
		return (1);
	start_game(&game);
	return (0);
}
