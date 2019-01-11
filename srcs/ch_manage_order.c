/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_manage_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:06:15 by erli              #+#    #+#             */
/*   Updated: 2019/01/11 19:09:41 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>




int					ch_manage_order(t_stacks *stacks, char *order)
{
	char	para[7];
	int		strlen;

	if (stacks == 0 || order == 0)
		return (ft_msg_int(2, "Stacks or order is NULL in man_order\n", -1));
	strlen = ft_strlen(order);
	if (strlen > 4 || order[strlen - 1] != '\n'
		|| ft_char_in_str(order[0], "spr") == 0)
		exit(ft_msg_int(2, "Error in manage\n", 0));
	ft_strcpy(para, "ch_");
	*ft_strchr(order, 10) = '\0';
	ft_strncpy(para + 3, order, strlen);
	if (order[0] == 's')
		ps_swap(stacks, NULL, para);
	else if (order[0] == 'p')
		ps_push(stacks, NULL, para);
	else if (order[0] == 'r' && strlen == 3)
		ps_rotate(stacks, NULL, para);
	else if (order[0] == 'r' && strlen == 4)
		ps_revrotate(stacks, NULL, para);
	else
		exit(ft_msg_int(2, "Error in mana\n", 14));
	return (0);
}
