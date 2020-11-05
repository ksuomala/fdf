# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/09 11:51:40 by ksuomala          #+#    #+#              #
#    Updated: 2020/10/21 22:54:07 by ksuomala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

SRCS = ft_strlen.c ft_putstr.c ft_putnbr.c ft_atoi.c ft_strdup.c ft_putchar.c\
ft_itoa.c ft_memdel.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c\
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c\
ft_strncmp.c ft_memset.c ft_memmove.c ft_memcpy.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_tolower.c ft_toupper.c ft_bzero.c ft_putnstr.c ft_putendl.c ft_n.c\
ft_memalloc.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strtrim.c ft_strjoin.c\
ft_strsplit.c ft_strsub.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c get_next_line.c ft_sqrt.c ft_lstnew.c ft_lstdelone.c\
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstfree.c ft_putnchar.c\
ft_itoa_base.c ft_toupper_str.c ft_strfjoin.c ft_swap_ptr.c ft_replace_ptr.c\
ft_count_digits_s.c ft_dtoa.c ft_strndup.c ft_mod_double.c ft_u_itoa_base.c\
ft_free2d.c ft_memdup.c

CC = gcc -Wall -Wextra -Werror -g -c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	make -C ft_printf/
	cp $(PRINTF) $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(SRCS)

clean:
	@rm -f $(OBJS)
	@make clean -C ft_printf/

fclean: clean
	@rm -f libft.a
	@rm -f $(PRINTF)

re: fclean $(NAME)

