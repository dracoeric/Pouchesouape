/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_chain_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:45:54 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 10:27:03 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sw_do_cmd(t_stacks *stacks, char *cmd, char c)
{
	if (c == '1')
		ps_swap(stacks, cmd, "sw_sa");
	else if (c == '2')
		ps_swap(stacks, cmd, "sw_sb");
	else if (c == '3')
		ps_swap(stacks, cmd, "sw_ss");
	else if (c == '4')
		ps_push(stacks, cmd, "sw_pa");
	else if (c == '5')
		ps_push(stacks, cmd, "sw_pb");
	else if (c == '6')
		ps_rotate(stacks, cmd, "sw_ra");
	else if (c == '7')
		ps_rotate(stacks, cmd, "sw_rb");
	else if (c == '8')
		ps_rotate(stacks, cmd, "sw_rr");
	else if (c == '9')
		ps_revrotate(stacks, cmd, "sw_rra");
	else if (c == 'a')
		ps_revrotate(stacks, cmd, "sw_rrb");
	else if (c == 'b')
		ps_revrotate(stacks, cmd, "sw_rrr");
}

void			sw_chain_cmd(t_stacks *stacks, char *cmd, char *list)
{
	int i;

	if (list == 0 || cmd == 0 || stacks == 0)
		return ;
	i = 0;
	while (list[i] != '\0')
	{
		sw_do_cmd(stacks, cmd, list[i]);
		i++;
	}
}
