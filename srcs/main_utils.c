/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:56:59 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/13 15:56:24 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char		free_data(t_data *data)
{
	if (!data)
		return (0);
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		free(data->mlx);
	free(data);
	return (0);
}

static char	ft_strcmp(char *s1, char *s2, int leng)
{
	int	i;

	i = 0;
	while (i < leng && *(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i++;
	}
	if (i == leng && !*(s1 + i) && !*(s2 + i))
		return (1);
	return (0);
}

char		check_parameter(char *str)
{
	int	leng;

	leng = 0;
	while (*(str + leng))
		leng++;
	if (ft_strcmp(str, "Julia", leng))
		return (1);
	else if (ft_strcmp(str, "Mandelbrot", leng))
		return (2);
	return (0);
}

void		assign_data(t_data *d)
{
	d->zoom = 5;
	d->f_ratio = 2;
	d->ratio_x = d->zoom / (double)d->w;
	d->ratio_y = d->zoom / (double)d->h;
	d->r = -d->zoom * 0.5;
	d->i = -d->zoom * 0.5;
	d->cr = 0;
	d->ci = 0;
	d->max = 100;
}

char		init_data(t_data *d, char *fractol_name)
{
	d->mlx = mlx_init();
	d->window = 0;
	d->image = 0;
	if (!d->mlx)
	{
		free_data(d);
		exit(1);
	}
	d->w = 800;
	d->h = 800;
	d->window = mlx_new_window(d->mlx, d->w, d->h, fractol_name);
	if (!d->window)
	{
		free_data(d);
		exit(1);
	}
	d->fractol = *fractol_name;
	assign_data(d);
	return (1);
}
