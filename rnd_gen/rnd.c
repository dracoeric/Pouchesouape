
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:55:24 by erli              #+#    #+#             */
/*   Updated: 2019/01/14 17:24:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <time.h>

static	void	print_it(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
}

static	int		rnd(int min, int max, int n)
{
	int		tab[n];
	int		num;
	int		i;
	int		mmax;

	if (max - min > RAND_MAX)
		return (ft_msg_int(2, "range is too big\n", 0));
	if (max <= min)
		return (ft_msg_int(2, "incorrect range\n", 0));
	if (max - min < 2 * n)
		return (ft_msg_int(2, "range too small\n", 0));
	i = 0;
	srand(time(NULL));
	mmax = max - min;
	while (i < n && i < 20000)
	{
		num = rand();
		num = (num % mmax) + min;
		if (ft_int_in_ptr(num, tab, i) == 0)
		{
			tab[i] = num;
			i++;
		}
	}
	print_it(tab, i);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc < 4)
		return (ft_msg_int(2, "./rnd min max num\n", 0));
	rnd(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
