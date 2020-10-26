# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 15:43:29 by mfalkrea          #+#    #+#              #
#    Updated: 2020/01/10 15:43:31 by mfalkrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a
C_FLS = ft_vec_sum.c ft_vec_mul.c ft_vec_dif.c \
		ft_vec_div.c ft_vec_scpr.c ft_vec_init.c \
		ft_vec_inv.c ft_vec_is_zero.c ft_vec_mod.c \
		ft_vec_unit.c
HEAD = libvec.h
FLAGS = -Wall -Wextra -Werror
O_FLS = $(C_FLS:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FLS)
	@ar rcs $(NAME) $(O_FLS)

%.o: %.c $(HEAD)
	@gcc $(FLAGS) -c $(C_FLS)

clean:
	@rm -f $(O_FLS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
