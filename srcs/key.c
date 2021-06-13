/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeon <seujeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:56:55 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 07:20:36 by seujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	x_icon(t_data *d)
{
	free_data(d);
	exit(0);
	return (0);
}

int	key_press(int key, t_data *d)
{
	if (key == 53)
	{
		free_data(d);
		exit(0);
	}
	return (0);
}

int	mouse_press(int key, int x, int y, t_data *d)
{
	x = 0;
	y = 0;
	if (key == 4 || key == 5)
		fractol(d, key, -1, -1);
	return (0);
}

int	mouse_pos(int x, int y, t_data *d)
{
	if (d->fractol == 'J' && 0 <= x && x < d->w && 0 <= y && y < d->h)
	{
		d->cr = 5 * (x - d->w * 0.5) / (double)d->w;
		d->ci = 5 * (y - d->h * 0.5) / (double)d->h;
		fractol(d, 0, -1, -1);
	}
	return (0);
}
