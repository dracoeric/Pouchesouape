/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:46:59 by erli              #+#    #+#             */
/*   Updated: 2019/01/14 19:13:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static	void	small_sort_3(t_stacks *stacks)
{
	int	*tab;

	tab = stacks->a;
	if (tab[0] < tab[1] && tab[0] < tab[2] && tab[1] < tab[2])
		return ;
	if (tab[0] < tab[1] && tab[0] < tab[2])
		write(stacks->fd, "sa\nra\n", 6);
	else if (tab[0] < tab[1])
		write(stacks->fd, "rra\n", 4);
	else if (tab[0] < tab[2])
		write(stacks->fd, "sa\n", 3);
	else if (tab[1] < tab[2])
		write(stacks->fd, "sa\nrra\n", 7);
	else if (tab[1] > tab[2])
		write(stacks->fd, "ra\n", 3);
}

static	void	small_sort_4(t_stacks *stacks)
{
	int	*tab;

	tab = stacks->a;
	if (sw_check_stacks(stacks) == 1)
		return ;
	write(stacks->fd, "pb\n", 3);
	ps_push(stacks, NULL, "ch_pb");
	small_sort_3(stacks);
	ft_merge_sort_tab(stacks->a, stacks->len_a, stacks->a);
	if (stacks->b[0] < tab[0])
		write(stacks->fd, "pa\n", 3);
	else if (stacks->b[0] < tab[1])
		write(stacks->fd, "pa\nsa\n", 6);
	else if (stacks->b[0] < tab[2])
		write(stacks->fd, "rra\npa\nra\nra\n", 13);
	else if (stacks->b[0] > tab[2])
		write(stacks->fd, "pa\nra\n", 6);
}

static	void	small_sort_5_continuation(t_stacks *stacks)
{
	int	*tab;

	tab = stacks->a;
	if (stacks->b[0] > tab[2])
		write(stacks->fd, "pa\npa\nra\nra\n", 12);
	else if (stacks->b[0] > tab[1] && stacks->b[1] > tab[2])
		write(stacks->fd, "rra\npa\nra\nra\npa\nra\n", 19);
	else if (stacks->b[0] > tab[1] && stacks->b[1] < tab[2])
		write(stacks->fd, "rra\npa\npa\nrra\nrra\n", 18);
	else if (stacks->b[0] > tab[0] && stacks->b[1] > tab[2])
		write(stacks->fd, "ra\npa\nrra\npa\nrra\n", 17);
	else if (stacks->b[0] > tab[0] && stacks->b[1] > tab[1])
		write(stacks->fd, "sa\nrra\npa\nrra\npa\nrra\n", 21);
	else if (stacks->b[0] > tab[0] && stacks->b[1] > tab[0])
		write(stacks->fd, "sa\nra\npa\npa\nrra\n", 16);
	else if (stacks->b[0] < tab[0] && stacks->b[1] > tab[2])
		write(stacks->fd, "pa\npa\nra\n", 9);
	else if (stacks->b[0] < tab[0] && stacks->b[1] > tab[1])
		write(stacks->fd, "pa\nrra\npa\nra\nra\n", 16);
	else if (stacks->b[0] < tab[0] && stacks->b[1] > tab[0])
		write(stacks->fd, "pa\nra\nra\npa\nrra\nrra\n", 20);
	else if (stacks->b[0] < tab[0] && stacks->b[1] < tab[0])
		write(stacks->fd, "sa\npa\npa\n", 9);
}

static	void	small_sort_5(t_stacks *stacks)
{
	int	*tab;

	tab = stacks->a;
	write(stacks->fd, "pb\npb\n", 6);
	ps_push(stacks, NULL, "ch_pb");
	ps_push(stacks, NULL, "ch_pb");
	small_sort_3(stacks);
	ft_merge_sort_tab(stacks->a, stacks->len_a, stacks->a);
	if (stacks->b[0] > stacks->b[1])
	{
		ps_swap(stacks, NULL, "ch_sb");
		write(stacks->fd, "sb\n", 3);
	}
	small_sort_5_continuation(stacks);
}

void			sw_small_sort(t_stacks *stacks)
{
	if (stacks->len == 2)
		write(stacks->fd, "sa\n", 3);
	else if (stacks->len == 3)
		small_sort_3(stacks);
	else if (stacks->len == 4)
		small_sort_4(stacks);
	else if (stacks->len == 5)
		small_sort_5(stacks);
}
