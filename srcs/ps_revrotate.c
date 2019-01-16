/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:46:01 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 12:56:12 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static	int		ch_revrotate(t_stacks *stacks, char *para)
{
	int	tmp;

	if (ft_strcmp(para, "ch_rra") == 0 && stacks->len_a >= 2)
	{
		tmp = (stacks->a)[stacks->len_a - 1];
		ps_move(stacks, "down", 1);
		(stacks->a)[0] = tmp;
	}
	else if (ft_strcmp(para, "ch_rrb") == 0 && stacks->len_b >= 2)
	{
		tmp = (stacks->b)[stacks->len_b - 1];
		ps_move(stacks, "down", 2);
		(stacks->b)[0] = tmp;
	}
	else if (ft_strcmp(para, "ch_rrr") == 0)
	{
		ch_revrotate(stacks, "ch_rra");
		ch_revrotate(stacks, "ch_rrb");
	}
	else if (!((ft_strcmp(para, "ch_rra") == 0 && stacks->len_a < 2)
			|| (ft_strcmp(para, "ch_rrb") == 0 && stacks->len_b < 2)))
		return (ft_msg_int(2, "Invalid instruction un ch_revrotate\n", -1));
	return (0);
}

static	int		sw_revrotate(t_stacks *stacks, char *cmd, char *para)
{
	if (ft_strcmp(para, "sw_rra") == 0 && stacks->len_a >= 2)
	{
		ch_revrotate(stacks, "ch_rra");
		sw_add_cmd(stacks, cmd, "rra");
		stacks->a_rotated -= 1;
	}
	else if (ft_strcmp(para, "sw_rrb") == 0 && stacks->len_b >= 2)
	{
		ch_revrotate(stacks, "ch_rrb");
		sw_add_cmd(stacks, cmd, "rrb");
	}
	else if (ft_strcmp(para, "sw_rrr") == 0)
	{
		ch_revrotate(stacks, "ch_rra");
		ch_revrotate(stacks, "ch_rrb");
		sw_add_cmd(stacks, cmd, "rrr");
	}
	else if (!((ft_strcmp(para, "sw_rra") == 0 && stacks->len_a < 2)
			|| (ft_strcmp(para, "sw_rrb") == 0 && stacks->len_b < 2)))
		return (ft_msg_int(2, "Invalid instruction un sw_revrotate\n", -1));
	return (0);
}

int				ps_revrotate(t_stacks *stacks, char *cmd, char *para)
{
	if (stacks == 0 || para == 0)
	{
		ft_msg_int(2, "Stacks, or para is NULL in revrotate\n", -1);
		exit(0);
	}
	if (ft_strncmp(para, "ch", 2) == 0)
		return (ch_revrotate(stacks, para));
	if (ft_strncmp(para, "sw", 2) == 0)
		return (sw_revrotate(stacks, cmd, para));
	else
		return (ft_msg_int(2, "Invalid instruction in revrotate/n", -1));
}
