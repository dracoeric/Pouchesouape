/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:56:47 by erli              #+#    #+#             */
/*   Updated: 2019/01/09 19:27:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CMD_BUFF_SIZE 4096
# define BUFF_SIZE 40

typedef	struct	s_stacks
{
	int	*a;
	int	*b;
	int	len;
	int	len_a;
	int	len_b;
	int	min;
	int	max;
	int	options;
	int	cursor;
}				t_stacks;

int				ps_next_line(int fd, char **order);
int				ps_arg_verif(int argc, char **argv);
void			ps_arg_add(t_stacks *stacks, int argc, char **argv);
int				ps_swap(t_stacks *stacks, char *cmd, char *para);
int				ps_move(t_stacks *stacks, char *para, int a_or_b);
int				ps_push(t_stacks *stacks, char *cmd, char *para);
int				ps_rotate(t_stacks *stacks, char *cmd, char *para);
int				ps_revrotate(t_stacks *stacks, char *cmd, char *para);
int				ch_manage_order(t_stacks *stacks, char *order);
void			sw_add_cmd(t_stacks *stacks, char *cmd, char *para);

#endif
