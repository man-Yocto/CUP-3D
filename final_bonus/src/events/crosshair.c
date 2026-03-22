/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:54:25 by aalkhaso          #+#    #+#             */
/*   Updated: 2026/03/22 16:54:26 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     draw_horizontal_line(t_img *img, int center_x, int center_y,
                int size, int color)
{
        int     x;

        x = center_x - size;
        while (x <= center_x + size)
        {
                put_pixel(img, x, center_y, color);
                x++;
        }
}

static void     draw_vertical_line(t_img *img, int center_x, int center_y, int size,
                int color)
{
        int     y;

        y = center_y - size;
        while (y <= center_y + size)
        {
                put_pixel(img, center_x, y, color);
                y++;
        }
}

void    draw_crosshair(t_img *img)
{
        int     center_x;
        int     center_y;
        int     color;
        int     size;

        center_x = WIN_W / 2;
        center_y = WIN_H / 2;
        color = 0x00FF00;
        size = 10;
        draw_horizontal_line(img, center_x, center_y, size, color);
        draw_vertical_line(img, center_x, center_y, size, color);
        put_pixel(img, center_x, center_y, 0xFFFFFF);
}