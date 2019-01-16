/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:55:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 10:32:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

static	int		get_options(char *str, int options)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
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
	stacks->options = options;
	stacks->fd = 1;
	if (options / 100 == 1)
	{
		stacks->fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (stacks->fd < 0)
			stacks->fd = 1;
	}
	ps_arg_add(stacks, argc, argv + (options / 100));
	sw_sort_stacks(stacks);
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
		if (ft_str_made_of_str(argv[i], "-f") == 1)
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
