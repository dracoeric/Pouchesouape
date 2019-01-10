/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:56:47 by erli              #+#    #+#             */
/*   Updated: 2019/01/10 18:28:43 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mlxadd.h"

# define CMD_BUFF_SIZE 4096
# define BUFF_SIZE 40
# define W_WIDTH 1920
# define W_HEIGHT 1080


typedef	struct	s_stacks
{
	int			*a;
	int			*b;
	int			len;
	int			len_a;
	int			len_b;
	
	int			min;
	int			max;
	int			cursor;

	int			options;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*imga;
	t_img		*imgb;
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
int				ch_init_visu(t_stacks *stacks);
void			ch_do_orders(t_stacks *stacks, char *path);
int				ch_win_close(void *arg);
int				ch_key_press(int key, void *arg);
void			ch_draw_step(t_stacks *stacks, char *order);
void			sw_add_cmd(t_stacks *stacks, char *cmd, char *para);

#endif
