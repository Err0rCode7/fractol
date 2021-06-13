/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:59:14 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 19:59:16 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct	s_data
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*adr;
	char	fractol;
	int		bpp;
	int		leng;
	int		endian;
	int		w;
	int		h;
	int		max;
	double	zoom;
	double	ratio_x;
	double	ratio_y;
	double	f_ratio;
	double	r;
	double	i;
	double	cr;
	double	ci;
}				t_data;

void			assign_data(t_data *d);
char			check_parameter(char *str);
char			init_data(t_data *data, char *fractol);
char			free_data(t_data *data);

void			fractol(t_data *data, int key, int x, int y);
int				mandelbrot(double r, double i, t_data *data);
int				julia(double r, double i, t_data *data);

int				key_press(int key, t_data *data);
int				mouse_press(int key, int x, int y, t_data *data);
int				mouse_pos(int x, int y, t_data *data);
int				x_icon(t_data *d);

#endif
