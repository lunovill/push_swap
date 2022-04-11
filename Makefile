# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunovill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 17:41:30 by lunovill          #+#    #+#              #
#    Updated: 2022/03/12 17:41:32 by lunovill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = sources/main.c\
	sources/check_all.c\
	sources/ft_search.c\
	sources/ft_pile_cal.c\
	sources/ft_index.c\
	sources/lst_add.c\
	sources/lst_init.c\
	sources/lst_new.c\
	sources/lst_print.c\
	sources/lst_rmv.c\
	sources/op_push.c\
	sources/op_rotate.c\
	sources/op_rotate_all.c\
	sources/op_rrotate.c\
	sources/op_rrotate_all.c\
	sources/op_swap.c\
	sources/pile_b.c\
	sources/pile_conv.c\
	sources/pile_free.c\
	sources/pile_min.c\
	sources/pile_max.c\
	sources/pile_identifier.c\
	sources/pile_is_sort.c\
	sources/pile_sort.c\
	sources/pile_update.c\
	sources/push_swap.c\

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objects

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -Ilibft/includes -Iincludes
LIBS = libft/libft.a

all : compilation $(NAME) $(OBJS_DIR)

compilation :
	@$(MAKE) -C ./libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)

clean :
	@$(MAKE) clean -C ./libft
	@rm -r $(OBJS_DIR)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm $(NAME)

re : fclean all

.PHONY: all clean fclean re
