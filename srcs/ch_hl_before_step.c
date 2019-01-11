/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_hl_before_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:15:23 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 15:00:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlxadd.h"
#include "libft.h"
#include <stdlib.h>

static	void	hl_top(t_stacks *stacks, int mode)
{
	t_pixcoord	pixl;
	t_pixcoord	pixr;
	int			*tab;

	tab = stacks->b;
	if (mode == 1)
		tab = stacks->a;
	else if (mode == 3)
	{
		hl_top(stacks, 1);
		hl_top(stacks, 2);
		return ;
	}
	ch_find_px(stacks, tab[0], &pixl, &pixr);
	pixl.py = 0;
	pixr.py = (W_HEIGHT / stacks->len);
	ch_num_put(stacks, pixl, pixr, 2 + mode);
}

static	void	hl_bot(t_stacks *stacks, int mode)
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
		hl_bot(stacks, 1);
		hl_bot(stacks, 2);
		return ;
	}
	ch_find_px(stacks, tab[len - 1], &pixl, &pixr);
	pixl.py = (W_HEIGHT / stacks->len) * (len - 1);
	pixr.py = (W_HEIGHT / stacks->len) * (len);
	ch_num_put(stacks, pixl, pixr, 2 + mode);
}

void			ch_hl_before_step(t_stacks *stacks, char *order)
{
	if (stacks == 0 || order == 0)
		exit(ft_msg_int(2, "stacks or order is null in hl before\n", 0));
	if (ft_strcmp(order, "ch_sa") || ft_strcmp(order, "ch_ra")
		|| ft_strcmp(order, "ch_pb"))
		hl_top(stacks, 1);
	if (ft_strcmp(order, "ch_sb") || ft_strcmp(order, "ch_rb")
		|| ft_strcmp(order, "ch_pa"))
		hl_top(stacks, 2);
	if (ft_strcmp(order, "ch_ss") || ft_strcmp(order, "ch_rr"))
		hl_top(stacks, 3);
	if (ft_strcmp(order, "ch_rra"))
		hl_bot(stacks, 1);
	if (ft_strcmp(order, "ch_rrb"))
		hl_bot(stacks, 1);
	if (ft_strcmp(order, "ch_rrr"))
		hl_bot(stacks, 1);
}
