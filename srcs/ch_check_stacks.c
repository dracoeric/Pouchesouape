/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:14:36 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 19:16:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ch_check_stacks(t_stacks *stacks)
{
	int i;

	i = 0;
	if (stacks->len == 1)
		write(1, "OK\n", 3);
	else
	{
		while (i + 1 < stacks->len)
		{
			if ((stacks->a)[i] > (stacks->a)[i + 1])
			{
				write(1, "KO\n", 3);
				exit(0);
			}
			i++;
		}
		write(1, "OK\n", 3);
	}
}