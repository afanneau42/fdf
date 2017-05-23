/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:24:20 by afanneau          #+#    #+#             */
/*   Updated: 2017/01/11 16:56:00 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_max(t_mlx *mlx)
{
	char	*line;
	int		i;

	i = 0;
	mlx->fd = open(mlx->file, O_RDONLY);
	mlx->max_y = 0;
	mlx->max_x = 0;
	if ((get_next_line(mlx->fd, &line)) > 0)
	{
		while (line[i])
		{
			while (line[i] != ' ' && line[i])
				i++;
			mlx->max_x++;
			while (line[i] == ' ' && line[i])
				i++;
		}
	}
	mlx->max_y++;
	while (get_next_line(mlx->fd, &line) > 0)
		mlx->max_y++;
	mlx->fd = open(mlx->file, O_RDONLY);
}

void	init_tab(t_mlx *mlx)
{
	char	*line;
	int		i;

	i = 0;
	init_max(mlx);
	mlx->tab = malloc(sizeof(int*) * mlx->max_y);
	while (get_next_line(mlx->fd, &line) > 0)
	{
		mlx->x = 0;
		i = 0;
		mlx->tab[mlx->y] = malloc(sizeof(int) * mlx->max_x);
		while (line[i])
		{
			while (line[i] == ' ' && line[i])
				i++;
			mlx->tab[mlx->y][mlx->x] = ft_atoi(line + i);
			while (line[i] != ' ' && line[i])
				i++;
			if (line[i])
				mlx->x++;
		}
		mlx->y++;
	}
	free(line);
}

void	define_pixel(t_mlx *mlx, int x, int y)
{
	mlx->pix_y = (y * mlx->spc);
	mlx->pix_x = (x * mlx->spc);
	mlx->iso_y = (CTE1 / 2 * mlx->pix_x) + (CTE2 / 2 * mlx->pix_y) + (2560 / 4);
	mlx->iso_x = (CTE1 * mlx->pix_x) - (CTE2 * mlx->pix_y) + (2560 / 2);
	if (mlx->tab[y][x] != 0)
		mlx->iso_y += (-(mlx->h)) * mlx->tab[y][x];
	mlx->iso_y += mlx->arrow_y * (mlx->win_h / mlx->max_y);
	mlx->iso_x += mlx->arrow_x * (mlx->win_l / mlx->max_x);
}

void	print(t_mlx *mlx)
{
	mlx_string_put(mlx->ad, mlx->win, 1175, 10, 0x00FFFFFF, mlx->file);
	mlx_string_put(mlx->ad, mlx->win, 10, 10, 0x00FFFFFF, "Quit : ESC");
	mlx_string_put(mlx->ad, mlx->win, 10, 1190, 0x00FFFFFF, "Zoom : Q / W");
	mlx_string_put(mlx->ad, mlx->win, 10, 1240, 0x00FFFFFF, "Height : + / -");
	mlx_string_put(mlx->ad, mlx->win, 10, 1290, 0x00FFFFFF, "Color : C");
	mlx_string_put(mlx->ad, mlx->win, 10, 1340, 0x00FFFFFF, "Debug mod : D");
	mlx->y = 0;
	while (mlx->y < mlx->max_y)
	{
		mlx->x = 0;
		while (mlx->x < mlx->max_x)
		{
			define_pixel(mlx, mlx->x, mlx->y);
			trace_line(mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}

void	init(t_mlx **mlx, char *file)
{
	*mlx = malloc(sizeof(t_mlx));
	(*mlx)->file = file;
	(*mlx)->y = 0;
	(*mlx)->x = 0;
	(*mlx)->pix_y = 0;
	(*mlx)->pix_x = 0;
	(*mlx)->arrow_y = 0;
	(*mlx)->arrow_x = 0;
	(*mlx)->color1 = 0x00FFFFFF;
	(*mlx)->color2 = 0x00FFFFFF;
	(*mlx)->color3 = 0x00FFFFFF;
	(*mlx)->color4 = 0x00FFFFFF;
	(*mlx)->ad = mlx_init();
	init_tab((*mlx));
	(*mlx)->h = 2;
	(*mlx)->spc = 10;
	(*mlx)->win_l = 2560;
	(*mlx)->win_h = 2560;
	(*mlx)->win = mlx_new_window((*mlx)->ad,
			(*mlx)->win_l, (*mlx)->win_h, "FDF");
}
