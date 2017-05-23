/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:09:50 by afanneau          #+#    #+#             */
/*   Updated: 2017/01/10 15:20:42 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_column(t_mlx *mlx, t_cor c1, t_cor c2)
{
	if (mlx->y < mlx->max_y - 1)
	{
		define_pixel(mlx, mlx->x, mlx->y + 1);
		c2.x = mlx->iso_x;
		c2.y = mlx->iso_y;
		if (c1.y <= c2.y && ft_abs(c2.x - c1.x) >= ft_abs(c2.y - c1.y))
			draw_case_four(mlx, c1, c2);
		else if (c1.y > c2.y && ft_abs(c2.x - c1.x) <= ft_abs(c2.y - c1.y))
			draw_case_three(mlx, c1, c2);
		else if (c2.y < c1.y)
			draw_case_four(mlx, c1, c2);
		else
			draw_case_two(mlx, c1, c2);
	}
}

void	trace_line(t_mlx *mlx)
{
	t_cor c1;
	t_cor c2;

	c1.x = mlx->iso_x;
	c1.y = mlx->iso_y;
	if (mlx->x < mlx->max_x - 1)
	{
		define_pixel(mlx, mlx->x + 1, mlx->y);
		c2.x = mlx->iso_x;
		c2.y = mlx->iso_y;
		if (c1.x <= c2.x && (c2.x - c1.x) >= ft_abs(c2.y - c1.y))
		{
			draw_case_one(mlx, c1, c2);
		}
		else if (c1.y < c2.y)
			draw_case_two(mlx, c1, c2);
		else
			draw_case_three(mlx, c1, c2);
	}
	c2.x = 0;
	trace_column(mlx, c1, c2);
}
