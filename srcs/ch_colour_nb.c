/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_colour_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:47:11 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 18:54:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "push_swap.h"
#include "libft.h"

t_colour	ch_colour_nb(int nb)
{
	if (nb == 1 || nb == 3)
		return (mlx_str_to_colour("0x00ab82ff"));
	return (mlx_str_to_colour("0x0012a682"));
}
