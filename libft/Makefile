# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 22:18:12 by lunovill          #+#    #+#              #
#    Updated: 2022/03/17 14:00:25 by lunovill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  srcs/ft_abs.c\
		srcs/ft_atoi.c\
		srcs/ft_atoui.c\
		srcs/ft_bzero.c\
		srcs/ft_calloc.c\
		srcs/ft_count_if.c\
		srcs/ft_display_file.c\
		srcs/ft_foreach.c\
		srcs/ft_ftab.c\
		srcs/ft_isalnum.c\
		srcs/ft_isalpha.c\
		srcs/ft_isascii.c\
		srcs/ft_isdigit.c\
		srcs/ft_isprint.c\
		srcs/ft_isset.c\
		srcs/ft_itoa.c\
		srcs/ft_memalloc.c\
		srcs/ft_memccpy.c\
		srcs/ft_memchr.c\
		srcs/ft_memcmp.c\
		srcs/ft_memcpy.c\
		srcs/ft_memdel.c\
		srcs/ft_memmove.c\
		srcs/ft_memset.c\
		srcs/ft_putchar.c\
		srcs/ft_putchar_fd.c\
		srcs/ft_putnbr.c\
		srcs/ft_putnbr_fd.c\
		srcs/ft_putstr.c\
		srcs/ft_putstr_fd.c\
		srcs/ft_putsub.c\
		srcs/ft_putunbr.c\
		srcs/ft_putunbr_fd.c\
		srcs/ft_realloc.c\
		srcs/ft_split.c\
		srcs/ft_strcat.c\
		srcs/ft_strchr.c\
		srcs/ft_strclr.c\
		srcs/ft_strcmp.c\
		srcs/ft_strcpy.c\
		srcs/ft_strdup.c\
		srcs/ft_strequ.c\
		srcs/ft_strichr.c\
		srcs/ft_strirchr.c\
		srcs/ft_strischr.c\
		srcs/ft_striter.c\
		srcs/ft_striteri.c\
		srcs/ft_strjoin.c\
		srcs/ft_strjoinf.c\
		srcs/ft_strlcat.c\
		srcs/ft_strlcpy.c\
		srcs/ft_strlen.c\
		srcs/ft_strmap.c\
		srcs/ft_strmapi.c\
		srcs/ft_strncat.c\
		srcs/ft_strncmp.c\
		srcs/ft_strncpy.c\
		srcs/ft_strnequ.c\
		srcs/ft_strnew.c\
		srcs/ft_strnstr.c\
		srcs/ft_strrchr.c\
		srcs/ft_strstr.c\
		srcs/ft_strsub.c\
		srcs/ft_strtrim.c\
		srcs/ft_tolower.c\
		srcs/ft_toupper.c\
		srcs/ft_uitoa.c\
		srcs/ft_xtoa.c\
		srcs/ft_printf/fg_check.c\
		srcs/ft_printf/fg_fldzr.c\
		srcs/ft_printf/fg_hyphen.c\
		srcs/ft_printf/fg_period.c\
		srcs/ft_printf/ft_atrkornb.c\
		srcs/ft_printf/ft_conv.c\
		srcs/ft_printf/ft_convc.c\
		srcs/ft_printf/ft_convi.c\
		srcs/ft_printf/ft_convn.c\
		srcs/ft_printf/ft_convp.c\
		srcs/ft_printf/ft_convs.c\
		srcs/ft_printf/ft_field.c\
		srcs/ft_printf/ft_zero.c\
		srcs/ft_printf/ft_printf.c\

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./includes

all: compilation $(NAME) $(OBJS_DIR)

compilation :
	@echo "libft : Compiling the 'srcs' files..."

$(NAME): $(OBJS)
	@echo "libft : Successful compilation of 'srcs' files."
	@echo "libft : Creating the library..."
	@ar rcs $(NAME) $(OBJS)
	@echo "libft : Successful creation of the library."

%.o : %.c
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(OBJS_DIR) :
	@echo "libft : Creating the '$(OBJS_DIR)' directory."
	@mkdir $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)

clean :
	@echo "libft : Deleting the '$(OBJS_DIR)' directory."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "libft : Deleting the '$(NAME)' directory."
	@rm -rf $(NAME)
re : fclean all

.PHONY: clean fclean all re
