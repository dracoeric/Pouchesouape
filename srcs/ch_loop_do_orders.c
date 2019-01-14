/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_get_old_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:47:50 by erli              #+#    #+#             */
/*   Updated: 2019/01/14 15:04:53 by erli             ###   ########.fr       */
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

static	char	*ch_get_old_order(t_stacks *stacks, char *order, int dir)
{
	if (stacks->order_buf[stacks->back_in_time] == 1)
		ft_strcpy(order, "sa\n");
	if (stacks->order_buf[stacks->back_in_time] == 2)
		ft_strcpy(order, "sb\n");
	if (stacks->order_buf[stacks->back_in_time] == 3)
		ft_strcpy(order, "ss\n");
	if (stacks->order_buf[stacks->back_in_time] == 4)
		ft_strcpy(order, (dir == 0 ? "pa\n" : "pb\n"));
	if (stacks->order_buf[stacks->back_in_time] == 5)
		ft_strcpy(order, (dir == 0 ? "pb\n" : "pa\n"));
	if (stacks->order_buf[stacks->back_in_time] == 6)
		ft_strcpy(order, (dir == 0 ? "ra\n" : "rra\n"));
	if (stacks->order_buf[stacks->back_in_time] == 7)
		ft_strcpy(order, (dir == 0 ? "rb\n" : "rrb\n"));
	if (stacks->order_buf[stacks->back_in_time] == 8)
		ft_strcpy(order, (dir == 0 ? "rr\n" : "rrr\n"));
	if (stacks->order_buf[stacks->back_in_time] == 9)
		ft_strcpy(order, (dir == 0 ? "rra\n" : "ra\n"));
	if (stacks->order_buf[stacks->back_in_time] == 10)
		ft_strcpy(order, (dir == 0 ? "rrb\n" : "rb\n"));
	if (stacks->order_buf[stacks->back_in_time] == 11)
		ft_strcpy(order, (dir == 0 ? "rrr\n" : "rr\n"));
	if (stacks->order_buf[stacks->back_in_time] == 0)
		(stacks->back_in_time)--;
	return (order);
}

static	void	ch_draw_order(t_stacks *stacks, char *order)
{
	ch_manage_order(stacks, order);
	if (stacks->options % 100 == 11)
		ch_draw_step(stacks, order, 2);
	else
		ch_draw_step(stacks, order, 0);
	free(order);
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
		order = ft_strdup(ch_get_old_order(stacks, old_order,
				stacks->forward_backward));
	else if ((ret = ps_next_line(stacks->fd, &order)) == 0)
		return (ch_check_stacks(stacks));
	if (order[0] == '\0')
		return (0);
	ch_manage_old_order(stacks, order);
	if (stacks->back_in_time > -1 && stacks->forward_backward == 0)
		(stacks->back_in_time)--;
	ch_draw_order(stacks, order);
	return (0);
}
