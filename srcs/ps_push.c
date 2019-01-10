/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:46:01 by erli              #+#    #+#             */
/*   Updated: 2019/01/10 11:55:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static	int		ch_push(t_stacks *stacks, char *para)
{
	int	tmp;

	if (ft_strcmp(para, "ch_pa") == 0 && stacks->len_b > 0)
	{
		tmp = (stacks->b)[0];
		ps_move(stacks, "up", 2);
		ps_move(stacks, "down", 1);
		(stacks->a)[0] = tmp;
		stacks->len_a += 1;
	}
	else if (ft_strcmp(para, "ch_pb") == 0 && stacks->len_a > 0)
	{
		tmp = (stacks->a)[0];
		ps_move(stacks, "up", 1);
		ps_move(stacks, "down", 2);
		(stacks->b)[0] = tmp;
		stacks->len_b += 1;
	}
	else if (!((ft_strcmp(para, "ch_pa") == 0 && stacks->len_a == 0)
			|| (ft_strcmp(para, "ch_pb") == 0 && stacks->len_b == 0)))
		return (ft_msg_int(2, "Invalid instruction un ch_push\n", -1));
	return (0);
}

static	int		sw_push(t_stacks *stacks, char *cmd, char *para)
{
	if (ft_strcmp(para, "sw_pa") == 0 && stacks->len_b > 0)
	{
		ch_push(stacks, "ch_pa");
		sw_add_cmd(stacks, cmd, "pa");
	}
	else if (ft_strcmp(para, "sw_pb") == 0 && stacks->len_a > 0)
	{
		ch_push(stacks, "ch_pb");
		sw_add_cmd(stacks, cmd, "pb");
	}
	else if (!((ft_strcmp(para, "sw_pa") == 0 && stacks->len_a == 0)
			|| (ft_strcmp(para, "sw_pb") == 0 && stacks->len_b == 0)))
		return (ft_msg_int(2, "Invalid instruction un sw_push\n", -1));
	return (0);
}

int				ps_push(t_stacks *stacks, char *cmd, char *para)
{
	if (stacks == 0 || para == 0)
	{
		ft_msg_int(2, "Stacks or para is NULL in push\n", -1);
		exit(0);
	}
	if (ft_strncmp(para, "ch", 2) == 0)
		return (ch_push(stacks, para));
	if (ft_strncmp(para, "sw", 2) == 0)
		return (sw_push(stacks, cmd, para));
	else
		return (ft_msg_int(2, "Invalid instruction in push/n", -1));
}
