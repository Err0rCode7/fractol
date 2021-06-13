/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:57:07 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 19:59:24 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	mandelbrot(double r, double i, t_data *d)
{
	int			j;
	double		zr;
	double		zi;
	double		tmp;

	zr = 0;
	zi = 0;
	j = 0;
	while (j < d->max && zr * zr + zi * zi < 4)
	{
		tmp = zr;
		zr = tmp * tmp - zi * zi + r;
		zi = 2 * tmp * zi + i;
		j++;
	}
	return (j);
}
