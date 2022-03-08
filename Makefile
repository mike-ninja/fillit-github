# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 11:57:21 by mbarutel          #+#    #+#              #
#    Updated: 2022/02/28 11:55:45 by lasalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = -Llibft -lft

GERR = gcc -c -Wall -Werror -Wextra

SRCS = main.c 
SRCS += ft_validator.c
SRCS += ft_createboard.c
SRCS += ft_square.c
SRCS += ft_instetri.c
SRCS += ft_solver.c
SRCS += ft_presets.c
SRCS += ft_term_del.c
SRCS += ft_printboard.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(OBJS) $(LIB) -o $(NAME)

$(OBJS): $(SRCS)
	$(GERR) $(SRCS)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all