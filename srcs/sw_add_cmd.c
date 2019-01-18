/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_add_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:06:17 by erli              #+#    #+#             */
/*   Updated: 2019/01/17 16:28:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		sw_add_cmd(t_stacks *stacks, char *cmd, char *para)
{
	int i;

	i = 0;
	if (cmd == 0 || para == 0)
	{
		ft_msg_int(2, "Error\n", -1);
		exit(0);
	}
	if (stacks->cursor + ft_strlen(para) < CMD_BUFF_SIZE)
	{
		while (para[i] != '\0')
		{
			cmd[stacks->cursor + i] = para[i];
			i++;
		}
		cmd[stacks->cursor + i] = '\n';
		stacks->cursor += i + 1;
	}
	else
	{
		write(stacks->fd, cmd, stacks->cursor);
		stacks->cursor = 0;
		ft_bzero(cmd, CMD_BUFF_SIZE + 1);
		sw_add_cmd(stacks, cmd, para);
	}
}
