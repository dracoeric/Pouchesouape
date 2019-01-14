/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_get_old_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:47:50 by erli              #+#    #+#             */
/*   Updated: 2019/01/14 10:22:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static	void	ch_manage_old_order(t_stacks *stacks, char *order)
{
	if (stacks->back_in_time != -1)
		return ;
	ft_memmove((stacks->order_buf + 1), stacks->order_buf, 4 * 99);
	if (ft_strcmp(order, "sa\n") == 0)
		stacks->order_buf[0] = 1;
	if (ft_strcmp(order, "sb\n") == 0)
		stacks->order_buf[0] = 2;
	if (ft_strcmp(order, "ss\n") == 0)
		stacks->order_buf[0] = 3;
	if (ft_strcmp(order, "pa\n") == 0)
		stacks->order_buf[0] = 4;
	if (ft_strcmp(order, "pb\n") == 0)
		stacks->order_buf[0] = 5;
	if (ft_strcmp(order, "ra\n") == 0)
		stacks->order_buf[0] = 6;
	if (ft_strcmp(order, "rb\n") == 0)
		stacks->order_buf[0] = 7;
	if (ft_strcmp(order, "rr\n") == 0)
		stacks->order_buf[0] = 8;
	if (ft_strcmp(order, "rra\n") == 0)
		stacks->order_buf[0] = 9;
	if (ft_strcmp(order, "rrb\n") == 0)
		stacks->order_buf[0] = 10;
	if (ft_strcmp(order, "rrr\n") == 0)
		stacks->order_buf[0] = 11;
}

static	char	*ch_get_old_order(t_stacks *stacks, char *order)
{
	if (stacks->order_buf[stacks->back_in_time] == 1)
		ft_strcpy(order, "sa\n");
	if (stacks->order_buf[stacks->back_in_time] == 2)
		ft_strcpy(order, "sb\n");
	if (stacks->order_buf[stacks->back_in_time] == 3)
		ft_strcpy(order, "ss\n");
	if (stacks->order_buf[stacks->back_in_time] == 4)
		ft_strcpy(order, "pa\n");
	if (stacks->order_buf[stacks->back_in_time] == 5)
		ft_strcpy(order, "pb\n");
	if (stacks->order_buf[stacks->back_in_time] == 6)
		ft_strcpy(order, "ra\n");
	if (stacks->order_buf[stacks->back_in_time] == 7)
		ft_strcpy(order, "rb\n");
	if (stacks->order_buf[stacks->back_in_time] == 8)
		ft_strcpy(order, "rr\n");
	if (stacks->order_buf[stacks->back_in_time] == 9)
		ft_strcpy(order, "rra\n");
	if (stacks->order_buf[stacks->back_in_time] == 10)
		ft_strcpy(order, "rra\n");
	if (stacks->order_buf[stacks->back_in_time] == 11)
		ft_strcpy(order, "rrr\n");
	(stacks->back_in_time)--;
	return (order);
}

int				ch_loop_do_orders(void *arg)
{
	t_stacks	*stacks;
	int			ret;
	char		old_order[10];
	char		*order;

	if (arg == 0)
		return (ft_msg_int(2, "arg is null in loop do orders\n", 0));
	stacks = (t_stacks *)arg;
	ft_bzero(old_order, 10);
	if (stacks->back_in_time != -1)
		order = ft_strdup(ch_get_old_order(stacks, old_order));
	else if ((ret = ps_next_line(stacks->fd, &order)) == 0)
		exit(ch_check_stacks(stacks));
	ch_manage_old_order(stacks, order);
	if (stacks->options % 100 == 11)
		ch_draw_step(stacks, order, 1);
	ch_manage_order(stacks, order);
	if (stacks->options % 100 == 11)
		ch_draw_step(stacks, order, 2);
	else if (stacks->options % 10 == 1)
		ch_draw_step(stacks, order, 0);
	free(order);
	return (0);
}
