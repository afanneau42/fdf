/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:14:59 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/23 14:49:08 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_case_one(t_mlx *mlx, t_cor c1, t_cor c2)
{
	int x;

	x = c1.x;
	while (x <= c2.x)
	{
		mlx_pixel_put(mlx->ad, mlx->win, x, c1.y +
				((c2.y - c1.y) * (x - c1.x)) / (c2.x - c1.x), mlx->color1);
		x++;
	}
}

void	draw_case_two(t_mlx *mlx, t_cor c1, t_cor c2)
{
	int y;

	y = c1.y;
	while (y <= c2.y)
	{
		mlx_pixel_put(mlx->ad, mlx->win, c1.x +
				((c2.x - c1.x) * (y - c1.y)) / (c2.y - c1.y), y, mlx->color2);
		y++;
	}
}

void	draw_case_three(t_mlx *mlx, t_cor c1, t_cor c2)
{
	int y;

	y = c1.y;
	while (y >= c2.y)
	{
		mlx_pixel_put(mlx->ad, mlx->win, c1.x +
				((c2.x - c1.x) * (y - c1.y)) / (c2.y - c1.y), y, mlx->color3);
		y--;
	}
}

void	draw_case_four(t_mlx *mlx, t_cor c1, t_cor c2)
{
	int x;

	x = c1.x;
	while (x >= c2.x)
	{
		mlx_pixel_put(mlx->ad, mlx->win, x, c1.y +
				((c2.y - c1.y) * (x - c1.x)) / (c2.x - c1.x), mlx->color4);
		x--;
	}
}
