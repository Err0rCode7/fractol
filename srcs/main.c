/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:57:03 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 19:59:33 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	run_program(t_data *data)
{
	mlx_mouse_hook(data->window, mouse_press, data);
	mlx_hook(data->window, 6, 0, mouse_pos, data);
	mlx_hook(data->window, 17, 0, x_icon, data);
	mlx_key_hook(data->window, key_press, data);
	mlx_loop(data->mlx);
}

int			main(int argc, char **argv)
{
	t_data		*data;

	if (argc == 2 && check_parameter(*(++argv)))
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		if (!init_data(data, *argv))
			return (0);
		fractol(data, 0, -1, -1);
		run_program(data);
	}
	printf("fractol list\n1. Julia\n2. Mandelbrot\n");
	return (0);
}
