# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunovill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 17:41:30 by lunovill          #+#    #+#              #
#    Updated: 2022/05/17 21:28:45 by lunovill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 #=============================================================================#
#								SOURCES											#
 #=============================================================================#
 
SRCS_DIR = sources
SRC_FILES = main\
		check_all\
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
		op_push\
		op_rotate\
		op_rotate_all\
		op_rrotate\
		op_rrotate_all\
		op_swap\
		pile_b\
		pile_conv\
		pile_free\
		pile_min\
		pile_max\
		pile_identifier\
		pile_is_sort\
		pile_sort\
		pile_update\
		push_swap\

SRCS = $(addsuffix .c, $(SRC_FILES))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

 #=============================================================================#
#									LIBRARY										#
 #=============================================================================#

LIBS_DIR = libft
LIBS = libft.a

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CIFLAGS = -Iincludes -I$(LIBS_DIR)/includes
CLFLAGS = -L$(LIBS_DIR) -lft

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(MAKE) -C $(LIBS_DIR)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) $(CLFLAGS) -o $(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(CIFLAGS) -c $< -o $@
clean :
	$(MAKE) clean -C $(LIBS_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBS_DIR)
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
re : fclean all

.PHONY: clean fclean all re
