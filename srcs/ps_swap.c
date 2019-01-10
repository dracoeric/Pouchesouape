/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:46:01 by erli              #+#    #+#             */
/*   Updated: 2019/01/10 11:58:18 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static	int		ch_swap(t_stacks *stacks, char *para)
{
	int	tmp;

	if (ft_strcmp(para, "ch_sa") == 0 && stacks->len_a >= 2)
	{
		tmp = (stacks->a)[0];
		(stacks->a)[0] = (stacks->a)[1];
		(stacks->a)[1] = tmp;
	}
	else if (ft_strcmp(para, "ch_sb") == 0 && stacks->len_b >= 2)
	{
		tmp = (stacks->b)[0];
		(stacks->b)[0] = (stacks->b)[1];
		(stacks->b)[1] = tmp;
	}
	else if (ft_strcmp(para, "ch_ss") == 0)
	{
		ch_swap(stacks, "ch_sa");
		ch_swap(stacks, "ch_sb");
	}
	else if (!((ft_strcmp(para, "ch_sa") == 0 && stacks->len_a < 2)
			|| (ft_strcmp(para, "ch_sb") == 0 && stacks->len_b < 2)))
		exit(ft_msg_int(2, "Invalid instruction un ch_swap\n", 0));
	return (0);
}

static	int		sw_swap(t_stacks *stacks, char *cmd, char *para)
{
	if (ft_strcmp(para, "sw_sa") == 0 && stacks->len_a >= 2)
	{
		ch_swap(stacks, "ch_sa");
		sw_add_cmd(stacks, cmd, "sa");
	}
	else if (ft_strcmp(para, "sw_sb") == 0 && stacks->len_b >= 2)
	{
		ch_swap(stacks, "ch_sb");
		sw_add_cmd(stacks, cmd, "sb");
	}
	else if (ft_strcmp(para, "sw_ss") == 0)
	{
		ch_swap(stacks, "ch_sa");
		ch_swap(stacks, "ch_sb");
		sw_add_cmd(stacks, cmd, "ss");
	}
	else if (!((ft_strcmp(para, "sw_sa") == 0 && stacks->len_a < 2)
			|| (ft_strcmp(para, "sw_sb") == 0 && stacks->len_b < 2)))
		exit(ft_msg_int(2, "Invalid instruction un sw_swap\n", 0));
	return (0);
}

int				ps_swap(t_stacks *stacks, char *cmd, char *para)
{
	if (stacks == 0 || para == 0)
	{
		ft_msg_int(2, "Stacks, cmd, or para is NULL in swap\n", -1);
		exit(0);
	}
	if (ft_strncmp(para, "ch", 2) == 0)
		return (ch_swap(stacks, para));
	if (ft_strncmp(para, "sw", 2) == 0)
		return (sw_swap(stacks, cmd, para));
	else
		exit(ft_msg_int(2, "Invalid instruction in swap/n", 0));
	return (0);
}
