#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylesik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 15:07:11 by ylesik            #+#    #+#              #
#    Updated: 2018/04/27 16:19:12 by nnaumenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fractol
LIBRARY		=	libft/libft.a
MLX_LIBRARY =	-I minilibx/
MLX_LIBRARY2 =	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

C_FDF		=	brezen_2.c pytha_tree.c fern.c julia.c f_asist.c main.c mandelbrot.c \
f_key.c main_helper.c ft_threads.c draw.c f_key_mous.c

OBJ_D = obj/
OBJ = $(addprefix $(OBJ_D), $(C_FDF:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	make re -C libft/
	$(CC) $(MLX_LIBRARY) $(OBJ) -o $(NAME) $(MLX_LIBRARY2) $(LIBRARY) $(FLAGS)

$(OBJ): | $(OBJ_D)

$(OBJ_D):
	mkdir $(OBJ_D)

$(OBJ_D)%.o: %.c
	gcc $(FLAGS) -o $@ -c $<
	gcc  -g -o $@ -c $<

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_D)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re