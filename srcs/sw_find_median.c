/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:06:36 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 10:11:00 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static	int	find_median(int *tab, int len)
{
	int	sorted[len];

	ft_merge_sort_tab(tab, sorted, len);
	return (sorted[len / 2]);
}

int			sw_find_median(int *tab, int len)
{
	if (len <= 0)
		return (0);
	else
		return (find_median(tab, len));
}
