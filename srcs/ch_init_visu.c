/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_init_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:31:51 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 18:32:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "push_swap.h"
#include "libft.h"

int			ch_init_visu(t_stacks *stacks)
{
	if (stacks == 0 || stacks->options % 10 == 0)
		return (0);
	if (!(stacks->mlx_ptr = mlx_init()))
		return (ft_msg_int(2, "X-server connection failed\n", 0));
	if (!(stacks->win_ptr = mlx_new_window(stacks->mlx_ptr, W_WIDTH,
										W_HEIGHT, "Checker")))
		return (ft_msg_int(2, "Could not create Window\n", 0));
	if (!(stacks->imga = mlx_img_create(stacks->mlx_ptr, W_WIDTH / 2,
										W_HEIGHT)))
		return (ft_msg_int(2, "Could not create imga\n", 0));
	if (!(stacks->imgb = mlx_img_create(stacks->mlx_ptr, W_WIDTH / 2,
			W_HEIGHT)))
		return (ft_msg_int(2, "Could not create Window imgb\n", 0));
	return (0);
}
