/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_win_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:50:30 by erli              #+#    #+#             */
/*   Updated: 2019/01/10 18:19:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlxadd.h"
#include <stdlib.h>

int	ch_win_close(void *arg)
{
	t_stacks	*stacks;

	if (arg == 0)
		return (0);
	stacks = (t_stacks *)arg;
	mlx_destroy_image(stacks->mlx_ptr, stacks->imga->ptr);
	mlx_destroy_image(stacks->mlx_ptr, stacks->imgb->ptr);
	mlx_destroy_window(stacks->mlx_ptr, stacks->win_ptr);
	free(stacks->imga);
	free(stacks->imgb);
	free(stacks);
	exit(0);
	return (0);
}
