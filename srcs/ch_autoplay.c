/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_autoplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:48:02 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 14:49:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ch_autoplay(void *arg)
{
	t_stacks *stacks;

	if (arg == 0)
		return (0);
	stacks = (t_stacks *)arg;
	if (stacks->auto_play == 1)
	{
		stacks->forward_backward = 0;
		ch_loop_do_orders(stacks);
	}
	return (0);
}
