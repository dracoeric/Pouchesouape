/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_num_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:26:06 by erli              #+#    #+#             */
/*   Updated: 2019/01/18 10:56:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlxadd.h"
#include "libft.h"

void	ch_num_put(t_stacks *stacks, t_pixcoord pixl,
					t_pixcoord pixr, int mode)
{
	t_pixcoord pix;

	pixl.pz = mode;
	pix.pz = mode;
	pix.px = pixr.px;
	while (pixl.py < pixr.py)
	{
		pix.py = pixl.py;
		if (pixl.pz % 2 == 1)
			mlx_line_put_img(stacks->imga, &pixl, &pix, &ch_colour_nb);
		else
			mlx_line_put_img(stacks->imgb, &pixl, &pix, &ch_colour_nb);
		pixl.py++;
	}
}
