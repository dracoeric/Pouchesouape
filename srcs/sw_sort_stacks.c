/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:36:42 by erli              #+#    #+#             */
/*   Updated: 2019/01/15 17:25:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void			sw_sort_stacks(t_stacks *stacks)
{
	if (sw_check_stacks(stacks) == 1 || stacks->len == 1)
		exit(0);
	if (stacks->len <= 5)
		sw_small_sort(stacks);
	else
		sw_median_sort(stacks);
	exit(0);
}
