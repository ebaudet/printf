# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:38:26 by ebaudet           #+#    #+#              #
#    Updated: 2019/02/06 01:13:05 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
FILES	= ft_printf.c put.c handler.c functions.c get_dec_lenght.c params.c
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= -I ./includes/
LIB		=  -L . libftprintf.a
FLAGS	 = -Wall -Wextra -Werror -fno-builtin -fno-stack-protector -pedantic -ansi
FLAGS_LESS = -Wall -Wextra -Werror
DEBUGFLG = -v -da -Q -fsanitize=address -g3
CC		= gcc
AR		= ar rc
RANLIB	= ranlib

all: $(NAME)

$(NAME): make_libft $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo "\n\n > Compilation \033[36mlibftprintf.a\033[m [\033[32mDONE\033[m]"

.obj/%.o: srcs/%.c
	@mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS_LESS) $(INC)
	@echo -n .

make_libft:
	@echo "Compilation de la libft :"
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@cp libft/includes/libft.h ./includes/

clean:
	@rm -rf .obj
	make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f test
	make -C libft fclean
	@rm -f includes/libft.h
	@echo "fclean : [\033[32mDONE\033[m]"

re: fclean all

test: all
	@cc main.c -o test $(INC) $(LIB)
	@echo "\n > \033[36mtest\033[m compilation [\033[32mDONE\033[m]\n"

file_right:
	@chmod -R +rw . includes/
	@echo "\n\n > apply correct right [\033[32mDONE\033[m]"

.PHONY: all clean fclean re test file_right
