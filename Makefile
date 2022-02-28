# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:25:41 by hrecolet          #+#    #+#              #
#    Updated: 2022/01/31 13:52:57 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/ft_atoi.c srcs/insert.c srcs/percentage.c srcs/push_move.c srcs/push_swap.c \
				srcs/rotate_move.c srcs/solve.c srcs/swap_move.c srcs/swap.c srcs/verif_input.c \
				srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_parse.c srcs/ft_split.c srcs/ft_is_space.c \
				srcs/ft_putstr.c srcs/free.c

INCL		=	push_swap.h

CC			=	gcc 

CFLAGS		=	-Wall -Werror -Wextra 

RM			=	rm -f

NAME		=	push_swap

OBJ			=	$(SRCS:.c=.o)

all			:	$(NAME) 


$(NAME)		:	$(OBJ) push_swap.h 
				$(CC) $(CFLAGS) $(OBJ) $(INCL) -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean		:	clean
				$(RM) $(NAME) $(BONUS_NAME) $(OBJ_BONUS)

re			:	fclean all

.PHONY		:	clean fclean re 
