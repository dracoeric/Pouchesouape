/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:55:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/09 16:25:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static	int		init_stacks(int argc, char **argv, int len)
{
	int			taba[len];
	int			tabb[len];
	t_stacks	*stacks;

	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		return (ft_msg_int(2, "Malloc Error\n", -1));
	stacks->len = len;
	stacks->a = taba;
	stacks->b = tabb;
	ps_arg_add(stacks, argc, argv);
	ft_printf("stack a :\n%4td", stacks->a, stacks->len_a);
	return (0);
}

int				main(int argc, char **argv)
{
	int len;

	if (argc == 1)
		return (ft_msg_int(2, "Error\n", 6));
	len = ps_arg_verif(argc, argv);
	if (len == 0)
		return (ft_msg_int(2, "Error\n", 6));
	init_stacks(argc, argv, len);
	return (0);
}
