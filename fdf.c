/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:31:08 by afanneau          #+#    #+#             */
/*   Updated: 2017/01/11 16:58:54 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_in(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] != '.' && str[i])
			i++;
		if (str[i] == '.' && str[i + 1] == 'f' && str[i + 2] == 'd' &&
				str[i + 3] == 'f' && str[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int		change_col(int color)
{
	if (color == 0x00FFFFFF)
		color = 0x00FF0000;
	else if (color == 0x00FF0000)
		color = 0x0000FF00;
	else if (color == 0x0000FF00)
		color = 0x000000FF;
	else
		color = 0x00FFFFFF;
	return (color);
}

void	set_debug_mod(t_mlx *mlx)
{
	if (mlx->color4 != 0x0000FFFF)
	{
		mlx->color1 = 0x00FF0000;
		mlx->color2 = 0x000000FF;
		mlx->color3 = 0x0000FF00;
		mlx->color4 = 0x0000FFFF;
	}
	else
	{
		mlx->color1 = 0x00FFFFFF;
		mlx->color2 = 0x00FFFFFF;
		mlx->color3 = 0x00FFFFFF;
		mlx->color4 = 0x00FFFFFF;
	}
}

int		my_fct(int key, void *mlx)
{
	key == 53 ? exit(0) : 0;
	if (((t_mlx*)mlx)->spc > 2)
		key == 12 ? ((t_mlx*)mlx)->spc-- : 0;
	key == 13 ? ((t_mlx*)mlx)->spc++ : 0;
	if (((t_mlx*)mlx)->h > 2)
		key == 78 ? ((t_mlx*)mlx)->h-- : 0;
	if (((t_mlx*)mlx)->h < 100)
		key == 69 ? ((t_mlx*)mlx)->h++ : 0;
	key == 2 ? set_debug_mod(mlx) : 0;
	key == 126 ? ((t_mlx*)mlx)->arrow_y-- : 0;
	key == 124 ? ((t_mlx*)mlx)->arrow_x++ : 0;
	key == 125 ? ((t_mlx*)mlx)->arrow_y++ : 0;
	key == 123 ? ((t_mlx*)mlx)->arrow_x-- : 0;
	key == 8 ? (((t_mlx*)mlx)->color1 = change_col(((t_mlx*)mlx)->color1)) : 0;
	key == 8 ? (((t_mlx*)mlx)->color2 = change_col(((t_mlx*)mlx)->color2)) : 0;
	key == 8 ? (((t_mlx*)mlx)->color3 = change_col(((t_mlx*)mlx)->color3)) : 0;
	key == 8 ? (((t_mlx*)mlx)->color4 = change_col(((t_mlx*)mlx)->color4)) : 0;
	mlx_clear_window(((t_mlx*)mlx)->ad, ((t_mlx*)mlx)->win);
	print((t_mlx*)mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong input", 2);
		return (1);
	}
	if (check_in(argv[1]) == 1)
	{
		ft_putendl_fd("Wrong input", 2);
		return (1);
	}
	init(&mlx, argv[1]);
	print(mlx);
	mlx_key_hook(mlx->win, my_fct, (void*)mlx);
	mlx_loop(mlx->ad);
	return (0);
}
