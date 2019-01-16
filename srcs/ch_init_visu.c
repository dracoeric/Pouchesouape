/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_init_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:31:51 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 17:29:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "push_swap.h"
#include "libft.h"

int			ch_init_visu(t_stacks *stacks)
{
	t_img imga[1];
	t_img imgb[1];

	if (stacks == 0 || stacks->options % 10 == 0)
		return (0);
	if (!(stacks->mlx_ptr = mlx_init()))
		return (ft_msg_int(2, "X-server connection failed\n", 0));
	if (!(stacks->win_ptr = mlx_new_window(stacks->mlx_ptr, W_WIDTH,
										W_HEIGHT, "Checker")))
		return (ft_msg_int(2, "Could not create Window\n", 0));
	stacks->imga = imga;
	stacks->imga = imgb;
	mlx_img_create(stacks->mlx_ptr, stacks->imga, W_WIDTH / 2, W_HEIGHT);
	mlx_img_create(stacks->mlx_ptr, stacks->imgb, W_WIDTH / 2, W_HEIGHT);
	return (0);
}
