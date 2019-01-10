/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:55:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/10 18:11:29 by erli             ###   ########.fr       */
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
		if (str[i] == 't' && (options / 10) % 10 == 0)
			options += 10;
		if (str[i] == 'f' && (options / 100) == 0)
			options += 100;
		i++;
	}
	return (options);
}

static	void	check_stacks(t_stacks *stacks)
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
	stacks->options = options;
	ps_arg_add(stacks, argc, argv + (options / 100));
	ch_init_visu(stacks);
	ch_do_orders(stacks, argv[1]);
	check_stacks(stacks);
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
		if (ft_str_made_of_str(argv[i], "-vtf") == 1)
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
