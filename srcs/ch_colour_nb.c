/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_colour_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:47:11 by erli              #+#    #+#             */
/*   Updated: 2019/01/14 15:37:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "push_swap.h"
#include "libft.h"

t_colour	ch_colour_nb(int nb)
{
	if (nb == 1 || nb == 6)
		return (mlx_str_to_colour(STACK_A_COL));
	if (nb == 2 || nb == 5)
		return (mlx_str_to_colour(STACK_B_COL));
	if (nb == 3 || nb == 4)
		return (mlx_str_to_colour(SWAP_COL));
	if (nb == 7 || nb == 8)
		return (mlx_str_to_colour(ROTATE_COL));
	if (nb == 9 || nb == 10)
		return (mlx_str_to_colour(REV_COL));
	return (mlx_str_to_colour("0x00ffffff"));
}
