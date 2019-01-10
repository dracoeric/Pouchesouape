/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:53:17 by erli              #+#    #+#             */
/*   Updated: 2019/01/10 18:29:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "mlxadd.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void			ch_do_orders(t_stacks *stacks, char *path)
{
	int		fd;
	char	*order;
	int		ret;

	fd = (stacks->options / 100 == 1 ? open(path, O_RDONLY) : 0);
	if (fd < 0)
	{
		write(2, "Error wrong file\n", 17);
		exit(0);
	}
	if (stacks->options % 10 == 1)
	{
		mlx_hook(stacks->win_ptr, 17, (1L << 17), &ch_win_close, stacks);
		mlx_hook(stacks->win_ptr, 2, (1L << 0), &ch_key_press, stacks);
		mlx_loop(stacks->mlx_ptr);
		ch_draw_step(stacks, "init");
	}
	while ((ret = ps_next_line(fd, &order)) == 1)
	{
		ch_manage_order(stacks, order);
		if (stacks->options % 10 == 1)
			ch_draw_step(stacks, order);
		free(order);
	}
}
