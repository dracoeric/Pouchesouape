/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_find_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:23:25 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 18:57:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

void		ch_find_px(t_stacks *stacks, int nb, t_pixcoord *pixl,
				t_pixcoord *pixr)
{
	if (stacks == 0 || pixl == 0 || pixr == 0)
		exit(ft_msg_int(2, "Null arg ptr in find px\n", 0));
	if (nb < 0)
	{
		pixl->px = W_WIDTH / 4 * ((double)1 - ((double)nb / stacks->min));
		pixr->px = W_WIDTH / 4;
	}
	else
	{
		pixl->px = W_WIDTH / 4;
		pixr->px = W_WIDTH / 4 * ((double)1 + ((double)nb / stacks->max));
	}
}
