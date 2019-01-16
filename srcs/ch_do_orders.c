/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:53:17 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 17:39:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "mlxadd.h"
#include <fcntl.h>
#include <stdlib.h>

static	void		ch_do_orders_visu(t_stacks *stacks, char *path)
{
	int		fd;

	fd = (stacks->options / 100 == 1 ? open(path, O_RDONLY) : 0);
	if (fd < 0)
		exit(ft_msg_int(2, "Error\n", 0));
	stacks->fd = fd;
	ch_draw_step(stacks, "init", 0);
	mlx_loop_hook(stacks->mlx_ptr, &ch_autoplay, stacks);
	mlx_hook(stacks->win_ptr, 17, (1L << 17), &ch_win_close, stacks);
	mlx_hook(stacks->win_ptr, 2, (1L << 0), &ch_key_press, stacks);
	mlx_loop(stacks->mlx_ptr);
}

static	void		ch_do_orders_no_visu(t_stacks *stacks, char *path)
{
	int		fd;
	char	*order;
	int		ret;

	fd = (stacks->options / 100 == 1 ? open(path, O_RDONLY) : 0);
	if (fd < 0)
		exit(ft_msg_int(2, "Error\n", 0));
	stacks->fd = fd;
	while ((ret = ps_next_line(stacks->fd, &order)) == 1)
	{
		ch_manage_order(stacks, order);
		free(order);
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
