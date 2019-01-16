/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:55:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 11:16:16 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static	int		get_options(char *str, int options)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'v' && options % 10 == 0)
			options += 1;
		if (str[i] == 'c' && options % 100 == 1)
			options += 10;
		if (str[i] == 'f' && (options / 100) == 0)
			options += 100;
		i++;
	}
	return (options);
}

static	int		init_stacks(int argc, char **argv, int len, int options)
{
	int			taba[len];
	int			tabb[len];
	t_stacks	*stacks;

	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		return (ft_msg_int(2, "Malloc Error\n", -1));
	stacks->len = len;
	stacks->a = taba;
	stacks->b = tabb;
	stacks->min = 2147483647;
	stacks->max = -2147483648;
	stacks->back_in_time = -1;
	stacks->forward_backward = 0;
	stacks->options = options;
	ps_arg_add(stacks, argc, argv + (options / 100));
	ch_init_visu(stacks);
	ch_do_orders(stacks, argv[1]);
	ch_check_stacks(stacks);
	free(stacks);
	return (0);
}

int				main(int argc, char **argv)
{
	int len;
	int i;
	int	options;
	int	loop;

	i = 1;
	loop = 1;
	options = 0;
	while (i < argc && argv[i][0] == '-' && loop == 1)
	{
		if (ft_str_made_of_str(argv[i], "-vcf") == 1)
		{
			options = get_options(argv[i], options);
			i++;
		}
		else
			loop = 0;
	}
	argc += 1 - i - (options / 100);
	argv = argv + i - 1;
	if (argc == 1 || !(len = ps_arg_verif(argc, argv + (options / 100))))
		return (ft_msg_int(2, "Error wrong arguments\n", 0));
	init_stacks(argc, argv, len, options);
	return (0);
}
