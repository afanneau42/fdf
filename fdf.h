/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:34:01 by afanneau          #+#    #+#             */
/*   Updated: 2017/01/18 17:28:21 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>

# define WIN_L 1280
# define WIN_H 2560

# define CTE1 0.5
# define CTE2 0.5
# define H 5
# define SPC 20

typedef struct	s_mlx
{
	void		*ad;
	void		*win;

	char		*file;
	int			fd;
	int			**tab;

	int			y;
	int			x;

	double		max_y;
	double		max_x;

	double		pix_y;
	double		pix_x;

	double		iso_y;
	double		iso_x;

	double		spc;
	double		h;

	int			win_l;
	int			win_h;

	double		arrow_y;
	double		arrow_x;

	int			color1;
	int			color2;
	int			color3;
	int			color4;

	double		nxt_x;
	double		nxt_y;
}				t_mlx;

typedef struct	s_cor
{
	double		x;
	double		y;
}				t_cor;

void			init(t_mlx **mlx, char *file);
void			print(t_mlx *mlx);
void			define_pixel(t_mlx *mlx, int x, int y);
void			trace_line(t_mlx *mlx);
void			draw_case_one(t_mlx *mlx, t_cor c1, t_cor c2);
void			draw_case_two(t_mlx *mlx, t_cor c1, t_cor c2);
void			draw_case_three(t_mlx *mlx, t_cor c1, t_cor c2);
void			draw_case_four(t_mlx *mlx, t_cor c1, t_cor c2);

#endif
