/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_hl_after_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:15:23 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 16:03:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlxadd.h"
#include "libft.h"
#include <stdlib.h>

static	void	hl_top(t_stacks *stacks, int mode, int order)
{
	t_pixcoord	pixl;
	t_pixcoord	pixr;
	int			*tab;

	tab = stacks->b;
	if (mode == 1)
		tab = stacks->a;
	else if (mode == 3)
	{
		hl_top(stacks, 1, order);
		hl_top(stacks, 2, order);
		return ;
	}
	ch_find_px(stacks, tab[0], &pixl, &pixr);
	pixl.py = 0;
	pixr.py = (W_HEIGHT / stacks->len);
	ch_num_put(stacks, pixl, pixr, mode + order);
}

static	void	hl_second(t_stacks *stacks, int mode, int order)
{
	t_pixcoord	pixl;
	t_pixcoord	pixr;
	int			*tab;

	tab = stacks->b;
	if (mode == 1)
		tab = stacks->a;
	else if (mode == 3)
	{
		hl_top(stacks, 1, order);
		hl_top(stacks, 2, order);
		return ;
	}
	ch_find_px(stacks, tab[1], &pixl, &pixr);
	pixl.py = (W_HEIGHT / stacks->len);
	pixr.py = (W_HEIGHT / stacks->len) * 2;
	ch_num_put(stacks, pixl, pixr, mode + order);
}

static	void	hl_bot(t_stacks *stacks, int mode, int order)
{
	t_pixcoord	pixl;
	t_pixcoord	pixr;
	int			*tab;
	int			len;

	tab = stacks->b;
	len = stacks->len_b;
	if (mode == 1)
	{
		tab = stacks->a;
		len = stacks->len_a;
	}
	else if (mode == 3)
	{
		hl_bot(stacks, 1, order);
		hl_bot(stacks, 2, order);
		return ;
	}
	ch_find_px(stacks, tab[len - 1], &pixl, &pixr);
	pixl.py = (W_HEIGHT / stacks->len) * (len - 1);
	pixr.py = (W_HEIGHT / stacks->len) * (len);
	ch_num_put(stacks, pixl, pixr, mode + order);
}

void			ch_hl_after_step(t_stacks *stacks, char *order)
{
	if (stacks == 0 || order == 0)
		exit(ft_msg_int(2, "stacks or order is null in hl before\n", 0));
	else if (!ft_strcmp(order, "sa"))
		hl_second(stacks, 1, 2);
	else if (!ft_strcmp(order, "sb"))
		hl_second(stacks, 2, 2);
	else if (!ft_strcmp(order, "ss"))
		hl_second(stacks, 3, 2);
	else if (!ft_strcmp(order, "pa"))
		hl_top(stacks, 1, 4);
	else if (!ft_strcmp(order, "pb"))
		hl_top(stacks, 2, 4);
	else if (!ft_strcmp(order, "ra"))
		hl_bot(stacks, 1, 6);
	else if (!ft_strcmp(order, "rb"))
		hl_bot(stacks, 2, 6);
	else if (!ft_strcmp(order, "rr"))
		hl_bot(stacks, 3, 6);
	else if (!ft_strcmp(order, "rra"))
		hl_top(stacks, 1, 8);
	else if (!ft_strcmp(order, "rrb"))
		hl_top(stacks, 2, 8);
	else if (!ft_strcmp(order, "rrr"))
		hl_top(stacks, 3, 8);
}
