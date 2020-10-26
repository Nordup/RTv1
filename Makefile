# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 15:43:17 by mfalkrea          #+#    #+#              #
#    Updated: 2020/01/10 15:43:19 by mfalkrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
COMP = gcc

#SYSTEM:
SYSTEM = $(shell uname)
MACOS = Darwin
LINYX = Linux

#FLAGS:
WWW = -Wall -Wextra -Werror
ifeq ($(SYSTEM), $(MACOS))
	FLAGS = -lmlx -framework OpenGL -framework AppKit
else ifeq ($(SYSTEM), $(LINYX))
	FLAGS = -lXext -lX11 -lm
endif

#DIR:
LIBVEC_DIR = ./libvec/
LIBFT_DIR = ./libft/
ifeq ($(SYSTEM), $(LINYX))
	MLX_DIR = ./miniLibX_linux/
else ifeq ($(SYSTEM), $(MACOS))
	MLX_DIR = ./miniLibX_macos/
endif
C_DIR = ./source/
INC = ./includes/
O_DIR = ./obj/

#HEAD:
RTV1_H = $(INC)rtv1.h

#LIB:
LIBVEC_A = $(LIBVEC_DIR)libvec.a
LIBFT_A = $(LIBFT_DIR)libft.a
MLX_A = $(MLX_DIR)libmlx.a

#FILES:
ifeq ($(SYSTEM), $(LINYX))
	C_FLS =	main_linux.c ft_key_linux.c call_make_picture.c \
			init_scene.c get_color.c discriminant.c \
			cone.c cylinder.c plane.c sphere.c \
			calculate_clr.c closest_figure.c circle.c read_vec.c
else ifeq ($(SYSTEM), $(MACOS))
	C_FLS =	main_macos.c ft_key_macos.c call_make_picture.c \
			init_scene.c get_color.c discriminant.c \
			cone.c cylinder.c plane.c sphere.c \
			calculate_clr.c closest_figure.c circle.c read_vec.c
endif
O_FLS = $(C_FLS:%.c=%.o)

SOURSES = $(addprefix $(C_DIR), $(C_FLS))
OBJECTS = $(addprefix $(O_DIR), $(O_FLS))
INCLUDES = -I $(INC) -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(LIBVEC_DIR)
LIBS = $(LIBFT_A) $(MLX_A) $(LIBVEC_A)

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(LIBVEC_A) $(O_DIR) $(OBJECTS) $(RTV1_H)
	$(COMP) -o $(NAME) $(OBJECTS) $(INCLUDES) $(LIBS) $(FLAGS)

$(O_DIR)%.o: $(C_DIR)%.c $(RTV1_H)
	$(COMP) $(WWW) -c $(INCLUDES) $< -o $@

$(LIBVEC_A):
	make -C $(LIBVEC_DIR)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(MLX_A):
	make -C $(MLX_DIR)

$(O_DIR):
	mkdir -p $(O_DIR)

clean:
	rm -rf $(O_DIR)
	make -C $(LIBFT_DIR)/ clean
	make -C $(LIBVEC_DIR)/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_A)
	rm -f $(LIBVEC_A)
	make -C $(MLX_DIR)/ clean

re: fclean all

.PHONY: all clean fclean re
