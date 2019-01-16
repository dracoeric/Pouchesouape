/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_median_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:25:32 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 15:36:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

static	void	sw_fill_3(t_stacks *stacks, char *cmd, int *len)
{
	if (*len == 1)
		return ;
	if (*len == 2 && stacks->a[0] > stacks->a[1])
		ps_swap(stacks, cmd, "sw_sa");
	else if (*len == 3)
	{
		if (stacks->a[0] < stacks->a[1] && stacks->a[1] < stacks->a[2])
			sw_chain_cmd(stacks, cmd, "");
		else if (stacks->a[0] < stacks->a[2] && stacks->a[2] < stacks->a[1])
			sw_chain_cmd(stacks, cmd, "619");
		else if (stacks->a[1] < stacks->a[0] && stacks->a[0] < stacks->a[2])
			ps_swap(stacks, cmd, "sw_sa");
		else if (stacks->a[2] < stacks->a[0] && stacks->a[0] < stacks->a[1])
			sw_chain_cmd(stacks, cmd, "6191");
		else if (stacks->a[1] < stacks->a[2] && stacks->a[2] < stacks->a[0])
			sw_chain_cmd(stacks, cmd, "1619");
		else if (stacks->a[2] < stacks->a[1] && stacks->a[1] < stacks->a[0])
			sw_chain_cmd(stacks, cmd, "16191");
	}
	stacks->n_sorted += *len;
	*len = 0;
}

static	void	sw_median_sort_fill_b(t_stacks *stacks, char *cmd)
{
	int med;
	int len;

	while (stacks->len_a - stacks->n_sorted > 1)
	{
		len = stacks->len_a - stacks->n_sorted;
		if (len < 4)
			sw_fill_3(stacks, cmd, &len);
		stacks->rotated = 0;
		med = sw_find_median(stacks->a, len);
		stacks->median_cut[stacks->len_med] = 0;
		while (stacks->median_cut[stacks->len_med] < (len / 2))
		{
			if (stacks->a[0] < med)
				ps_push(stacks, cmd, "sw_pb");
			else
				ps_rotate(stacks, cmd, "sw_ra");
		}
		stacks->len_med = (len >= 4 ? (stacks->len_med) + 1 : stacks->len_med);
		while (stacks->rotated > 0 && stacks->n_sorted > 0)
			ps_revrotate(stacks, cmd, "sw_rra");
	}
}

static	void	sw_unload_3(t_stacks *stacks, char *cmd)
{
	if (stacks->median_cut[stacks->len_med - 1] == 2)
	{
		if (stacks->b[0] < stacks->b[1])
			ps_swap(stacks, cmd, "sw_sb");
		sw_chain_cmd(stacks, cmd, "44");
		stacks->n_sorted += 2;
		stacks->len_med -= 1;
		stacks->median_cut[stacks->len_med] = 0;
		return ;
	}
	else if (stacks->b[0] < stacks->b[1] && stacks->b[1] < stacks->b[2])
		sw_chain_cmd(stacks, cmd, "242414");
	else if (stacks->b[0] < stacks->b[2] && stacks->b[2] < stacks->b[1])
		sw_chain_cmd(stacks, cmd, "744a4");
	else if (stacks->b[1] < stacks->b[0] && stacks->b[0] < stacks->b[2])
		sw_chain_cmd(stacks, cmd, "42414");
	else if (stacks->b[2] < stacks->b[0] && stacks->b[0] < stacks->b[1])
		sw_chain_cmd(stacks, cmd, "2444");
	else if (stacks->b[1] < stacks->b[2] && stacks->b[2] < stacks->b[0])
		sw_chain_cmd(stacks, cmd, "4244");
	else if (stacks->b[2] < stacks->b[1] && stacks->b[1] < stacks->b[0])
		sw_chain_cmd(stacks, cmd, "444");
	stacks->n_sorted += 3;
	stacks->len_med -= 1;
	stacks->median_cut[stacks->len_med] = 0;
}

static	void	sw_median_sort_unload_b(t_stacks *stacks, char *cmd)
{
	int len;
	int med;

	if (stacks->len_med == 0)
		return ;
	if (stacks->median_cut[stacks->len_med - 1] <= 3)
		sw_unload_3(stacks, cmd);
	else
	{
		len = stacks->median_cut[stacks->len_med - 1];
		stacks->rotated = 0;
		med = sw_find_median(stacks->b, len);
		while (stacks->median_cut[stacks->len_med - 1] > (len / 2))
		{
			if (stacks->b[0] >= med)
			{
				ps_push(stacks, cmd, "sw_pa");
				stacks->median_cut[stacks->len_med - 1] -= 1;
			}
			else
				ps_rotate(stacks, cmd, "sw_rb");
		}
		while (stacks->rotated > 0 && stacks->n_sorted > 0)
			ps_revrotate(stacks, cmd, "sw_rrb");
	}
}

void			sw_median_sort(t_stacks *stacks)
{
	int		median_cut[stacks->len];
	char	cmd[CMD_BUFF_SIZE + 1];

	if (stacks == 0)
		return ;
	ft_bzero(cmd, CMD_BUFF_SIZE + 1);
	stacks->median_cut = median_cut;
	stacks->len_med = 0;
	stacks->n_sorted = 0;
	stacks->cursor = 0;
	sw_median_sort_fill_b(stacks, cmd);
	while (stacks->n_sorted != stacks->len)
	{
		sw_median_sort_unload_b(stacks, cmd);
		sw_median_sort_fill_b(stacks, cmd);
	}
	write(stacks->fd, cmd, stacks->cursor);
}
