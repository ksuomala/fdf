# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 14:08:38 by ksuomala          #+#    #+#              #
#    Updated: 2020/11/05 20:26:26 by ksuomala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c read_map.c mlx_keys.c draw_map.c colors.c scale.c\
convert_coordinates.c

SRCS_DIR = srcs/

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

OBJ_DIR = obj

LIBFT = libft/libft.a

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

LINKS = -I libft/ -L libft \
	-I /usr/local/include -L /usr/local/lib \
	-l mlx -l ft -framework OpenGL -framework Appkit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LINKS)
	@echo "executable compiled!"

$(OBJS): $(LIBFT) $(SRCS) $(OBJ_DIR)
	@echo "Compiling..."
	@$(CC) $(FLAGS) -c $(SRCS) -I libft
	@echo "Compiled. Moving .o files..."
	@mv $(SRCS:.c=.o) $(OBJ_DIR)/

$(LIBFT):
	@make -C libft

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@echo "*.o removed!"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Targets removed!"

re: fclean all