/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arg_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:48:13 by erli              #+#    #+#             */
/*   Updated: 2019/01/17 13:19:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static	int		count_nb(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
			i++;
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
			i++;
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (count);
}

int				ps_arg_verif(int argc, char **argv)
{
	int i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_str_made_of_str(argv[i], "+- \t\v\n\r\f0123456789") == 0)
			return (0);
		count += count_nb(argv[i]);
		i++;
	}
	return (count);
}
