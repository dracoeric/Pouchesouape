/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arg_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:48:13 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 11:22:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static	void	add_int_in_stacks(t_stacks *stacks, int nb, int *len)
{
	if (ft_int_in_ptr(nb, stacks->a, *len) == 1)
	{
		write(2, "Error doublon\n", 6);
		exit(0);
	}
	if (stacks->min > nb)
		stacks->min = nb;
	if (nb > (stacks->max))
		stacks->max = nb;
	(stacks->a)[*len] = nb;
	*len += 1;
}

static	int		ps_is_int(int nb, char *str, int *i, int sgn)
{
	if (nb > 214748364 || (nb == 214748364 && (str[*i] > '8'
		|| (str[*i] == '8' && sgn == 1))))
	{
		write(2, "Invalid arguments, please put valid integers.\n", 46);
		exit(0);
	}
	nb = (nb * 10) + (int)str[*i] - 48;
	*i += 1;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		write(2, "Invalid arguments, please put valid integers.\n", 46);
		exit(0);
	}
	return (nb * sgn);
}

static	int		ps_atoi(char *str, int *i, int sgn)
{
	int nb;
	int nb_len;

	nb = 0;
	nb_len = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (nb_len == 9)
			return (ps_is_int(nb, str, i, sgn));
		nb = (nb * 10) + (int)str[*i] - 48;
		*i += 1;
		nb_len++;
	}
	return (sgn * nb);
}

static	void	ps_parse_atoi(t_stacks *stacks, char *str, int *len)
{
	int				nb;
	int				i;
	int				sgn;

	i = 0;
	while (str[i] != '\0')
	{
		sgn = 1;
		while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			sgn = 44 - str[i];
			i++;
		}
		if (str[i] == '\0')
			return ;
		nb = ps_atoi(str, &i, sgn);
		add_int_in_stacks(stacks, nb, len);
	}
}

void			ps_arg_add(t_stacks *stacks, int argc, char **argv)
{
	int i;
	int len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		ps_parse_atoi(stacks, argv[i], &len);
		i++;
	}
	if (len != stacks->len)
	{
		write(2, "Len!= po_arg_verif\n", 19);
		exit(0);
	}
	stacks->len_a = len;
	stacks->len_b = 0;
}
