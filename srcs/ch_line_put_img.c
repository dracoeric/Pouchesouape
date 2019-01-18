/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_line_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:33:10 by erli              #+#    #+#             */
/*   Updated: 2019/01/18 10:55:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"

static	void	draw_line_case1(t_img *img, t_pixcoord *a,
			t_pixcoord *b, t_colour (*f)(int))
{
	int			i;
	int			j;
	t_colour	*int_ptr;

	if (a->px < 0 || b->px < 0 || a->py < 0
		|| a->px > img->size_line / img->bypp
		|| a->px > img->size_line / img->bypp || a->py > img->nb_line)
		return ;
	i = a->px * (img->bypp) + a->py * img->size_line;
	j = b->px * (img->bypp) + b->py * img->size_line;
	while (i <= j)
	{
		if (i > img->size_line * a->py && i < (img->size_line * (a->py + 1)))
		{
			int_ptr = (t_colour *)((img->str) + i);
			int_ptr[0] = f(a->pz);
		}
		i += 4;
	}
}

void			ch_line_put_img(t_img *img, t_pixcoord *a,
			t_pixcoord *b, t_colour (*f)(int))
{
	if (img == 0 || a == 0 || b == 0)
		return ;
	draw_line_case1(img, a, b, f);
	return ;
}
