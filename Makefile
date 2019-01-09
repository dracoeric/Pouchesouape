#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 14:34:35 by erli              #+#    #+#              #
#    Updated: 2019/01/09 11:53:00 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1		=		checker
NAME2		=		push_swap

SRCSDIR		=		./srcs
OBJSDIR		=		./objs

SRCS1		=		main_checker.c			ps_swap.c				ps_move.c		\
					ps_push.c				ps_rotate.c				sw_add_cmd.c

SRCS2		=		main_push_swap.c		ps_swap.c				ps_move.c		\
					ps_push.c				ps_rotate.c				sw_add_cmd.c	\
					

OBJS1		=		$(addprefix $(OBJSDIR)/, $(SRCS1:.c=.o))
OBJS2		=		$(addprefix $(OBJSDIR)/, $(SRCS2:.c=.o))

CC			=		gcc -g

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/ -I libft/includes/

RM			=		rm -f

LIB			=		libft/libft.a


all			:		$(NAME1) $(NAME2)

$(NAME1)	:		$(OBJS1) $(LIB) includes/push_swap.h
					$(CC) $(CFLAG) $(INCL) $(OBJS1) $(LIB) -o $(NAME1)

$(NAME2)	:		$(OBJS2) $(LIB) includes/push_swap.h
					$(CC) $(CFLAG) $(OBJS2) $(LIB) -o $(NAME2)

$(LIB)			:		
					make -C libft/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/push_swap.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) -c $< -o $@

val1		:		$(OBJS1) $(LIB) includes/push_swap.h
					$(CC) -g $(CFLAG) $(OBJS1) $(LIB) -o $(NAME1)

val2		:		$(OBJS2) $(LIB) includes/push_swap.h
					$(CC) -g $(CFLAG) $(OBJS2) $(LIB) -o $(NAME2)

clean		:
					$(RM) $(OBJS1) $(OBJS2)

fclean		:		
					$(RM) $(NAME1) $(NAME2)

re			:		fclean	all

delsav		:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*\#
					$(RM) */\#*\#

.PHONY		:		clean fclean re delsav