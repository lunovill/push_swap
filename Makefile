# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunovill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 05:19:02 by lunovill          #+#    #+#              #
#    Updated: 2022/10/02 18:02:27 by lunovill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
SRC_FILES = check_all\
		ft_search\
		ft_search_pa\
		ft_three\
		ft_index\
		ft_next_pa\
		lst_add\
		lst_init\
		lst_new\
		lst_print\
		lst_rmv\
		main\
		op_push\
		op_rotate\
		op_rotate_all\
		op_rrotate\
		op_rrotate_all\
		op_swap\
		pile_b\
		pile_conv\
		pile_free\
		pile_max\
		pile_min\
		pile_identifier\
		pile_is_sort\
		pile_sort\
		pile_update\
		push_swap\

SRCS = $(addsuffix .c, $(SRC_FILES))

SRCS_DIR_BONUS = bonus
SRC_FILES_BONUS = check_all\
					checker\
					ft_index\
					lst_add\
					lst_init\
					lst_new\
					lst_print\
					lst_rmv\
					op_push\
					op_rotate\
					op_rrotate\
					op_swap\
					pile_conv\
					pile_free\
					pile_max\
					pile_min\
					pile_is_sort\

SRCS_BONUS = $(addsuffix .c, $(SRC_FILES_BONUS))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR_BONUS = objets_bonus
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR_BONUS)/%.o)

 #=============================================================================#
#									LIBRARY										#
 #=============================================================================#

LIBFT_DIR = libft

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes -I$(LIBFT_DIR)/includes
LIBFLAGS = -L$(LIBFT_DIR) -lft

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = push_swap
NAME_BONUS = checker

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJS_DIR) :
	$(MAKE) -C $(LIBFT_DIR)
	mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c ./includes/$(NAME).h
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

$(OBJS_DIR_BONUS) :
	$(MAKE) -C $(LIBFT_DIR)
	mkdir $(OBJS_DIR_BONUS)

$(NAME_BONUS) : $(OBJS_DIR_BONUS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS_BONUS) $(LIBFLAGS) -o $(NAME_BONUS)

$(OBJS_BONUS) : $(OBJS_DIR_BONUS)/%.o : $(SRCS_DIR_BONUS)/%.c ./includes/$(NAME_BONUS).h
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_DIR_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY: all bonus clean fclean re
