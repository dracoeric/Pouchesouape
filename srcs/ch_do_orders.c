/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:53:17 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 19:30:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "mlxadd.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static	void	manage_old_order(t_stacks *stacks, char *order)
{
	if (stacks->back_in_time != -1)
		return ;
	ft_memmove((stacks->order_buf + 1), stacks->order, 4 * 99);
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

static	void	*get_old_order(t_stacks *stacks, char *order)
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
}

int				loop_do_orders(void *arg)
{
	t_stacks	*stacks;
	int			ret;
	char		order[10];

	if (arg == 0)
		return (ft_msg_int(2, "arg is null in loop do orders\n", 0));
	stacks = (t_stacks *)arg;
	ft_bzero(order, 10);
	if (stacks->back_in_time != -1)
		get_old_order(stacks, order);
	else if ((ret = ps_next_line(stacks->fd, &order)) == 0)
	{
		ch_check_stacks(stacks);
		return (0);
	}
	manage_old_order(stacks, order);
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

static	void		ch_do_orders_visu(t_stacks *stacks, char *path)
{
	int		fd;

	fd = (stacks->options / 100 == 1 ? open(path, O_RDONLY) : 0);
	if (fd < 0)
		exit(ft_msg_int(2, "Error wrong file\n", 0));
	stacks->fd = fd;
	ch_draw_step(stacks, "init", 0);
	mlx_hook(stacks->win_ptr, 17, (1L << 17), &ch_win_close, stacks);
	mlx_hook(stacks->win_ptr, 2, (1L << 0), &ch_key_press, stacks);
	mlx_loop(stacks->mlx_ptr);
}

static	void		ch_do_orders_no_visu(t_stacks *stacks, char *path)
{
	int		fd;
	char	order[10];
	int		ret;

	fd = (stacks->options / 100 == 1 ? open(path, O_RDONLY) : 0);
	if (fd < 0)
		exit(ft_msg_int(2, "Error wrong file\n", 0));
	stacks->fd = fd;
	ft_bzero(order, 10);
	while ((ret = ps_next_line(stacks->fd, &order)) == 1)
	{
		if (stacks->options % 100 == 11)
			ch_draw_step(stacks, order, 1);
		ch_manage_order(stacks, order);
		if (stacks->options % 100 == 11)
			ch_draw_step(stacks, order, 2);
		else if (stacks->options % 10 == 1)
			ch_draw_step(stacks, order, 0);
		free(order);
		return ;
	}
	return ;
}

void				ch_do_orders(t_stacks *stacks, char *path)
{
	if (stacks == 0 || path == 0)
		exit(ft_msg_int(2, "stack or path null in do orders\n", 0));
	if (stacks->options % 10 == 1)
		ch_do_orders_visu(stacks, path);
	else
		ch_do_orders_no_visu(stacks, path);
}
