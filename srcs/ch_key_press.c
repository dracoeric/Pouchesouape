/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:44:00 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 17:49:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static	void	go_forward(t_stacks *stacks)
{
	stacks->auto_play = 0;
	stacks->forward_backward = 0;
	ch_loop_do_orders(stacks);
}

static	void	go_backward(t_stacks *stacks)
{
	stacks->auto_play = 0;
	if (stacks->back_in_time < 99)
	{
		stacks->forward_backward = -1;
		(stacks->back_in_time)++;
		ch_loop_do_orders(stacks);
	}
}

int				ch_key_press(int key, void *arg)
{
	t_stacks	*stacks;

	if (arg == 0)
		return (0);
	stacks = (t_stacks *)arg;
	if (key == 9)
		stacks->auto_play = 1;
	if (key == 11)
		go_backward(stacks);
	if (key == 49)
		go_forward(stacks);
	if (key == 53)
	{
		mlx_destroy_image(stacks->mlx_ptr, stacks->imga->ptr);
		mlx_destroy_image(stacks->mlx_ptr, stacks->imgb->ptr);
		mlx_destroy_window(stacks->mlx_ptr, stacks->win_ptr);
		free(stacks->imga);
		free(stacks->imgb);
		exit(0);
	}
	return (0);
}
