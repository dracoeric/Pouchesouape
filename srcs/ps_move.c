/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:43:34 by erli              #+#    #+#             */
/*   Updated: 2019/01/09 11:19:21 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static	int		move_up(t_stacks *stacks, int a_or_b)
{
	if (a_or_b == 1 && stacks->len_a > 0)
	{
		ft_memmove(((stacks->a) + 1), stacks->a, 4 * (stacks->len_a - 1));
		stacks->len_a -= 1;
	}
	else if (a_or_b == 2 && stacks->len_b > 0)
	{
		ft_memmove(((stacks->b) + 1), stacks->b, 4 * (stacks->len_b - 1));
		stacks->len_b -= 1;
	}
	else if (a_or_b == 3)
	{
		move_up(stacks, 1);
		move_up(stacks, 2);
	}
	else
		return (ft_msg_int(2, "Invalid parameter in move_up\n", -1));
	return (0);
}

static	int		move_down(t_stacks *stacks, int a_or_b)
{
	if (a_or_b == 1 && stacks->len_a > 0)
		ft_memmove(stacks->a, ((stacks->a) + 1), 4 * stacks->len_a);
	else if (a_or_b == 2 && stacks->len_b > 0)
		ft_memmove(stacks->b, ((stacks->b) + 1), 4 * stacks->len_b);
	else if (a_or_b == 3)
	{
		move_down(stacks, 1);
		move_down(stacks, 2);
	}
	else
		return (ft_msg_int(2, "Invalid parameter in move_down\n", -1));
	return (0);
}

int				ps_move(t_stacks *stacks, char *para, int a_or_b)
{
	if (stacks == 0 || para == 0)
		return (ft_msg_int(2, "stacks or para is NULL in ps_move\n", -1));
	if (ft_strcmp(para, "up") == 0)
		return (move_up(stacks, a_or_b));
	if (ft_strcmp(para, "down") == 0)
		return (move_down(stacks, a_or_b));
	else
		return (ft_msg_int(2, "Invalid instruction in ps_move/n", -1));
}
