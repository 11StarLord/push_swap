# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 12:23:33 by djoao             #+#    #+#              #
#    Updated: 2024/09/23 12:23:37 by djoao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Ift_printf

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = ./srcs/push_swap.c \
       ./srcs/operations_1.c \
       ./srcs/operations_2.c \
       ./srcs/operations_3.c \
       ./srcs/utils_1.c \
       ./srcs/utils_2.c \
       ./srcs/utils_3.c \
       ./srcs/utils_4.c \
       ./srcs/organize.c \
       ./srcs/check_error.c

GREEN = \033[32m
RESET = \033[0m
RED = \033[31m

OBJS = $(SRCS:.c=.o)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o push_swap
	@sleep 1
	clear
	@printf "$(GREEN)." ; #sleep 1
	@printf "$(GREEN)." ; #sleep 1
	@printf "$(GREEN)." ; #sleep 1
	@printf "$(GREEN)Push Swap is READY!$(RESET)\n"

all:	$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f push_swap
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@sleep 1
	clear
	@printf "$(RED)." ; #sleep 1
	@printf "$(RED)." ; #sleep 1
	@printf "$(RED)." ; #sleep 1
	@printf "$(RED)Push swap END!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
