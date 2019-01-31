# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:38:26 by ebaudet           #+#    #+#              #
#    Updated: 2019/01/31 20:07:13 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FILES	= ft_printf.c put.c handler.c functions.c get_dec_lenght.c params.c \
		  lib/ft_atoi.c lib/ft_dtoa.c lib/ft_itoa.c lib/ft_lutohex.c \
		  lib/ft_lutooct.c lib/ft_memalloc.c lib/ft_memset.c lib/ft_putchar.c \
		  lib/ft_putendl.c lib/ft_putnbr.c lib/ft_putstr.c lib/ft_strcat.c \
		  lib/ft_strchr.c lib/ft_strcpy.c lib/ft_strdup.c lib/ft_strjoin.c \
		  lib/ft_strlen.c lib/ft_strncat.c lib/ft_strncpy.c lib/ft_toupper.c \
		  lib/ft_fabs.c lib/ft_strreverse.c
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= ./includes/ -I ./libft/includes
LIB		=  -L . libftprintf.a
FLAGS	 = -Wall -Wextra -Werror -fno-builtin -fno-stack-protector -pedantic -ansi
FLAGS_LESS = -Wall -Wextra -Werror
DEBUGFLG = -v -da -Q
CC		= gcc
AR		= ar rc
RANLIB	= ranlib

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo "\n\n > Compilation \033[36mlibftprintf.a\033[m [\033[32mDONE\033[m]"

.obj/%.o: srcs/%.c
	@mkdir -p .obj .obj/lib
	@$(CC) -c $< -o $@ $(FLAGS_LESS) -I $(INC)
	@echo -n .

# make_libft:
# 	@echo "Compilation de la libft :"
# 	@make -C libft

clean:
	@rm -rf .obj
	make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f test
	make -C libft fclean
	@echo "fclean : [\033[32mDONE\033[m]"

re: fclean all

test: all
	@cc $(FLAGS_LESS) main.c -o test -I $(INC) $(LIB)
	@echo "\n > \033[36mtest\033[m compilation [\033[32mDONE\033[m]\n"

file_right:
	@chmod -R +rw . includes/
	@echo "\n\n > apply correct right [\033[32mDONE\033[m]"

.PHONY: all clean fclean re test file_right
