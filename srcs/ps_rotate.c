/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:46:01 by erli              #+#    #+#             */
/*   Updated: 2019/01/18 11:17:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static	int		ch_rotate(t_stacks *stacks, char *para)
{
	int	tmp;

	if (ft_strcmp(para, "ch_ra") == 0 && stacks->len_a >= 2)
	{
		tmp = (stacks->a)[0];
		ps_move(stacks, "up", 1);
		(stacks->a)[stacks->len_a] = tmp;
		stacks->len_a += 1;
	}
	else if (ft_strcmp(para, "ch_rb") == 0 && stacks->len_b >= 2)
	{
		tmp = (stacks->b)[0];
		ps_move(stacks, "up", 2);
		(stacks->b)[stacks->len_b] = tmp;
		stacks->len_b += 1;
	}
	else if (ft_strcmp(para, "ch_rr") == 0)
	{
		ch_rotate(stacks, "ch_ra");
		ch_rotate(stacks, "ch_rb");
	}
	else if (!((ft_strcmp(para, "ch_ra") == 0 && stacks->len_a < 2)
			|| (ft_strcmp(para, "ch_rb") == 0 && stacks->len_b < 2)))
		exit(ft_msg_int(2, "Error\n", -1));
	return (0);
}

static	int		sw_rotate(t_stacks *stacks, char *cmd, char *para)
{
	if (ft_strcmp(para, "sw_ra") == 0 && stacks->len_a >= 2)
	{
		ch_rotate(stacks, "ch_ra");
		sw_add_cmd(stacks, cmd, "ra");
		stacks->rotated += 1;
	}
	else if (ft_strcmp(para, "sw_rb") == 0 && stacks->len_b >= 2)
	{
		ch_rotate(stacks, "ch_rb");
		sw_add_cmd(stacks, cmd, "rb");
		stacks->rotated += 1;
	}
	else if (ft_strcmp(para, "sw_rr") == 0)
	{
		ch_rotate(stacks, "ch_ra");
		ch_rotate(stacks, "ch_rb");
		sw_add_cmd(stacks, cmd, "rr");
	}
	else if (!((ft_strcmp(para, "sw_ra") == 0 && stacks->len_a < 2)
			|| (ft_strcmp(para, "sw_rb") == 0 && stacks->len_b < 2)))
		exit(ft_msg_int(2, "Error\n", -1));
	return (0);
}

int				ps_rotate(t_stacks *stacks, char *cmd, char *para)
{
	if (stacks == 0 || para == 0)
	{
		ft_msg_int(2, "Stacks, or para is NULL in rotate\n", -1);
		exit(0);
	}
	if (ft_strncmp(para, "ch", 2) == 0)
		return (ch_rotate(stacks, para));
	if (ft_strncmp(para, "sw", 2) == 0)
		return (sw_rotate(stacks, cmd, para));
	else
		exit(ft_msg_int(2, "Error\n", -1));
	return (0);
}
