/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_median_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:25:32 by erli              #+#    #+#             */
/*   Updated: 2019/01/15 18:31:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

static	int		sw_find_median(int *tab, int len)
{
	int	sorted[len];

	ft_merge_sort_tab(tab, sorted, len);
	return (sorted[len \ 2]);
}

static	void	sw_median_sort_fill_b(t_stacks *stacks, char *cmd)
{
	int med;
	int	count;
	int len;

	if (stacks->n_sorted == stacks->len)
		return ;
	while (stacks->len_a != stacks->n_sorted)
	{
		len = stacks->len_a - stacks->n_sorted;
		med = sw_find_median(stacks->a, len);
		count = 0;
		while (count < (len / 2) + (len % 1))
		{
			if (stacks->a[0] >= med)
			{
				ps_push(stacks, cmd, "sw_pb");
				count++;
			}
			else
				ps_rotate(stacks, cmd, "sw_ra");
		}
		stacks->median_cut[stacks->len_med] = count;
		(stacks->len_med)++;
	}
	
}

static	void	sw_unload_3(t_stacks *stacks, char *cmd)
{


}

static	void	sw_median_sort_unload(t_stacks *stacks, char *cmd)
{
	if (stacks->len_med == 0)
		return ;
	if (stacks->median_cut[stacks->len_med -1] == 2)
	{
		if (stacks->b[0] < stacks->b[1])
			ps_push(stacks, cmd, "sw_sb");
		ps_push(stacks, cmd, "sw_pa");
		ps_push(stacks, cmd, "sw_pa");
		stacks->n_sorted += 2;
		stacks->len_med -= 1;
		stacks->median_cut[stacks->len_med] = 0;			
	}
	else if (stacks->median_cut[stacks->len_med -1] == 3)
		sw_unload_3(stacks, cmd);
	else
	{
		while (stacks->median_cut[stacks->len_med -1] > 0)
		{
			ps_push(stacks, cmd, "sw_pa");
			stacks->median_cut[stacks->len_med - 1] -= 1;
		}
		stacks->len_med -= 1;
	}
}

void	sw_median_sort(t_stacks *stacks)
{
	int		median_cut[stacks->len];
	char	*cmd[CMD_BUFF_SIZE + 1];

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
}
