/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_check_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:40:27 by erli              #+#    #+#             */
/*   Updated: 2019/01/14 16:45:13 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sw_check_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	if (stacks->len_b != 0 || stacks->len_a != stacks->len)
		return (0);
	while (i + 1 < stacks->len_a)
	{
		if ((stacks->a)[i] > (stacks->a)[i + 1])
			return (0);
		i++;
	}
	return (1);
}
