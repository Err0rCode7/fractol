/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:56:49 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:00:18 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	julia(double r, double i, t_data *d)
{
	int		j;
	double	tmp;

	j = 0;
	while (j < d->max && r * r + i * i < 4)
	{
		tmp = r;
		r = tmp * tmp - i * i + d->cr;
		i = 2 * tmp * i + d->ci;
		j++;
	}
	return (j);
}
