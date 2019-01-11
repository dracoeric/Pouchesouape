/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_draw_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:23:58 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 18:36:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mlxadd.h"
#include "libft.h"
#include <stdlib.h>

static	void	draw_stacka(t_stacks *stacks)
{
	int			i;
	t_pixcoord	pix_top_left;
	t_pixcoord	pix_bot_right;
	int			py;

	i = 0;
	py = 0;
	while (i < stacks->len_a)
	{
		pix_top_left.py = py;
		pix_bot_right.py = (W_HEIGHT / stacks->len) * (1 + i);
		ch_find_px(stacks, (stacks->a)[i], &pix_top_left, &pix_bot_right);
		ch_num_put(stacks, pix_top_left, pix_bot_right, 1);
		py = pix_bot_right.py;
		i++;
	}

}

static	void	draw_stackb(t_stacks *stacks)
{
	int			i;
	t_pixcoord	pix_top_left;
	t_pixcoord	pix_bot_right;
	int			py;

	i = 0;
	py = 0;
	while (i < stacks->len_b)
	{
		pix_top_left.py = py;
		ch_find_px(stacks, (stacks->b)[i], &pix_top_left, &pix_bot_right);
		pix_bot_right.py = (W_HEIGHT / stacks->len) * (1 + i);
		ch_num_put(stacks, pix_top_left, pix_bot_right, 2);
		py = pix_bot_right.py;
		i++;
	}
}

void			ch_draw_step(t_stacks *stacks, char *order, int mode)
{
	if (stacks == 0 || order == 0)
		exit(ft_msg_int(2, "Stacks or order is null in draw_Step\n", 0));
	if (stacks->options / 10 % 10 == 1 && mode == 1)
		ch_hl_before_step(stacks, order);
	else if (stacks->options / 10 % 10 == 1 && mode == 2)
		ch_hl_after_step(stacks, order);
	else
	{
		ft_bzero(stacks->imga->str, stacks->imga->nb_line
			* stacks->imga->size_line);
		ft_bzero(stacks->imgb->str, stacks->imgb->nb_line
			* stacks->imgb->size_line);
		draw_stacka(stacks);
		draw_stackb(stacks);
	}
	mlx_put_image_to_window(stacks->mlx_ptr, stacks->win_ptr, stacks->imga->ptr,
		0, 0);
	mlx_put_image_to_window(stacks->mlx_ptr, stacks->win_ptr, stacks->imgb->ptr,
		W_WIDTH / 2, 0);
	return ;
}